# from app import Application
from app.upscale import main as entrypoint
import sys


def main() -> None:
    # app = Application()
    # app.run()
    args = sys.argv[1:]
    entrypoint(args)


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("ctrl+c: shutting down...")
    except Exception as err:
        print("error:", err)
