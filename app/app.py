import os
from PIL import Image
import pillow_avif
from pillow_heif import register_heif_opener
from .args import CommandLineArgs


class Application:
    ignored_exts: list[str] = [".DS_Store"]
    args: CommandLineArgs

    def __init__(self) -> None:
        self.args = CommandLineArgs()
        register_heif_opener()

    def run(self) -> None:
        files = os.listdir(self.args.base_path)
        for file in files:
            full_path = os.path.join(self.args.base_path, file)
            if os.path.isdir(full_path):
                continue

            if self.is_ignored_file(full_path):
                print("[Skipping] ", full_path)
                continue

            try:
                self.process_image(full_path, self.args.base_path, file)
            except Exception as ex:
                print(f"[Skipping] {file}, error: ", ex)

    def process_image(self, full_path: str, base_path: str, file: str):
        # uniform convert and resize image.
        image = Image.open(full_path).convert("RGB")
        image.thumbnail(self.args.dimensions)

        out_dir = os.path.join(base_path, "out")
        if not os.path.exists(out_dir):
            os.makedirs(out_dir)

        out_path = os.path.join(out_dir, self.get_filename(file, "jpg"))
        print("[Done] ", out_path)
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
