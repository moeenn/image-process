from PIL import Image
import os


class Application:
    def run(self, args: list[str]) -> None:
        if len(args) == 1:
            base_path = args[0]
        else:
            base_path = os.getcwd()

        files = os.listdir(base_path)
        for file in files:
            full_path = os.path.join(base_path, file)
            image = Image.open(full_path)
            image = image.convert("RGB")

            out_dir = os.path.join(base_path, "out")
            if not os.path.exists(out_dir):
                os.makedirs(out_dir)

            out_path = os.path.join(out_dir, self.get_filename(file, "jpg"))
            print("[Done] ", out_path)
            image.save(out_path)

    def get_filename(self, file: str, ext: str) -> str:
        pieces = file.split(".")
        if len(pieces) != 2:
            return f"{file}.{ext}"

        return f"{pieces[0]}.{ext}"
