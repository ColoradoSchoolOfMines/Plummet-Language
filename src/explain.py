import sys

#
# NOTE: This part of the program will explain an error code produced by the
#       compiler. It should take in a code then print out the help page for that
#       specific error code.
#

def helpCommand():
    print("Usage: Subcommand: explain [error code]")

if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] == "help":
        helpCommand()
        sys.exit(0)

    if len(sys.argv) != 2:
        helpCommand()
        sys.exit(4)

    print(f"explain called: {sys.argv}")