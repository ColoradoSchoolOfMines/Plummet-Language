import sys

#
# TODO: This part of the program will explain an error code produced by the
#       compiler. It should take in a code then print out the help page for that
#       specific error code.
#

if __name__ == "__main__":
    print(sys.argv)
    
    if len(sys.argv) != 2:
        print("Usage: Subcommand: explain [error code]")
        sys.exit(4)

    print("explain called")