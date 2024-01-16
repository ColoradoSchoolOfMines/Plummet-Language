import sys

#
# TODO: Make a standard for library packages. They will need to follow a certain
#       structure in order to be installed. If they do not follow this structure
#       this program should give a error code that can be ran through the
#       explain.py subprogram.
#

def helpCommand():
    print("Usage: Subcommand: package [install/uninstall] [link to git repository]")

if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] == "help":
        helpCommand()
        sys.exit(0)

    if len(sys.argv) != 3 or sys.argv[1] not in ["install", "uninstall"]:
        helpCommand()
        sys.exit(4)

    print(f"package called: {sys.argv}")