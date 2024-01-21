import sys

def helpCommand():
    print("Usage: Subcommand: new [library/program]")

if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] == "help":
        helpCommand()
        sys.exit(0)

    if len(sys.argv) != 2 or sys.argv[1] not in ["library", "program"]:
        helpCommand()
        sys.exit(4)

    print(f"new called: {sys.argv}")