from app.app import Application
import sys


def main() -> None:
    args = sys.argv[1:]
    app = Application()
    app.run(args)


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("ctrl+c: shutting down...")
    except Exception as err:
        print("error: ", err)
