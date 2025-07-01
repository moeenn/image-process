from app import Application


def main() -> None:
    app = Application()
    app.run()


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("ctrl+c: shutting down...")
    except Exception as err:
        print("error:", err)
