import os
import sys

FILE_LOCATION: str = os.path.dirname(__file__)

def help_command():
    print("Usage: Subcommand: explain [error code | help]")


def get_error_messages() -> list[str]:
    return os.listdir(f"{FILE_LOCATION}/error_messages/")


def validate_error_code(code: str) -> bool:
    error_messages: list[str] = get_error_messages()
    return code in error_messages


def print_error_message(code: str) -> None:
    print(open(f"{FILE_LOCATION}/error_messages/{code}", "r").read())


if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] == "help":
        help_command()
        sys.exit(0)

    if len(sys.argv) != 2:
        help_command()
        sys.exit(4)

    error_code: str = sys.argv[1]

    if not validate_error_code(error_code):
        print(f"Error: Invalid error code. -- {error_code}")
        sys.exit(4)

    print_error_message(error_code)