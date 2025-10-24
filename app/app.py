from dataclasses import dataclass
import os
from PIL import Image
import pillow_avif
from pillow_heif import register_heif_opener
from .args import CommandLineArgs


class Color:
    RED = "\033[31m"
    RESET = "\033[0m"


@dataclass
class ErroredImage:
    file: str
    err: str


class Application:
    ignored_exts: list[str] = [".DS_Store"]
    args: CommandLineArgs
    image_count = 0
    done_count = 0

    def __init__(self) -> None:
        self.args = CommandLineArgs()
        register_heif_opener()

    def mark_done(self) -> None:
        self.done_count += 1
        print(f"\rCompleted: {self.done_count:03d}/{self.image_count:03d}", end="")

    def run(self) -> None:
        errored: list[ErroredImage] = []
        files = os.listdir(self.args.base_path)
        self.image_count = len(files)

        for file in files:
            full_path = os.path.join(self.args.base_path, file)
            if os.path.isdir(full_path):
                self.image_count -= 1
                continue

            if self.is_ignored_file(full_path):
                self.image_count -= 1
                continue

            try:
                self.process_image(full_path, self.args.base_path, file)
                self.mark_done()
            except Exception as ex:
                errored.append(ErroredImage(file=file, err=str(ex)))

        if len(errored) == 0:
            print("\nDone!")
        else:
            print(f"{Color.RED}\nFiles to convert following files:")
            for entry in errored:
                print(f"\t{entry.file}: {entry.err}")

            print(f"{Color.RESET}", end="")

    def process_image(self, full_path: str, base_path: str, file: str) -> None:
        # uniform convert and resize image.
        image = Image.open(full_path).convert("RGB")
        image.thumbnail(self.args.dimensions)

        out_dir = os.path.join(base_path, "out")
        if not os.path.exists(out_dir):
            os.makedirs(out_dir)

        out_path = os.path.join(out_dir, self.get_filename(file, "jpg"))
        image.save(out_path)

    def is_ignored_file(self, path: str) -> bool:
        for ignored_ext in self.ignored_exts:
            if path.endswith(ignored_ext):
                return True

        return False

    def get_filename(self, file: str, ext: str) -> str:
        pieces = file.split(".")
        if len(pieces) != 2:
            return f"{file}.{ext}"

        return f"{pieces[0]}.{ext}"
