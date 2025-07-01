import argparse
import os


class CommandLineArgs:
    base_path: str = os.getcwd()
    compress: bool = True
    dimensions: tuple[int, int] = (1920, 1080)

    def __init__(self) -> None:
        parser = argparse.ArgumentParser(description="Compress and convert image files")
        parser.add_argument("-i", "--input", help="path to input directory")
        parser.add_argument(
            "-c",
            "--compress",
            action="store_true",
            help="Apply compression on input images",
        )
        parser.add_argument(
            "-d",
            "--dimensions",
            help="Max dimensions for compressed images (format: width,heigth)",
        )
        raw_args = parser.parse_args()

        raw_input = raw_args.input
        raw_dimensions = raw_args.dimensions

        if raw_input is not None:
            self.base_path = raw_input

        self.compress = raw_args.compress
        if raw_dimensions is not None:
            self.dimensions = self.parse_dimensions(raw_dimensions)

    def parse_dimensions(self, raw: str) -> tuple[int, int]:
        pieces = raw.split(",")
        if len(pieces) != 2:
            raise Exception(
                "invalid value provided for --dimensions: Expected format: width,height"
            )

        width = self.parse_int("width", pieces[0])
        heigth = self.parse_int("height", pieces[1])
        return (width, heigth)

    def parse_int(self, id: str, input: str) -> int:
        try:
            return int(input)
        except Exception:
            raise Exception(f"invalid value provded for {id}")
