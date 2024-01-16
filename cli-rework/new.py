import sys

if __name__ == "__main__":
    print(sys.argv)

    if len(sys.argv) > 1:
        print("Usage: Subcommand: new")
        sys.exit(4)

    print("new called")