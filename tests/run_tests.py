import os
import sys
import subprocess

FILE_LOCATION: str = os.path.dirname(__file__) + "/"
TESTS_LOCATION: str = os.path.join(FILE_LOCATION, "test_files/")
DIFFS_LOCATION: str = os.path.join(FILE_LOCATION, "diffs/")

def print_help() -> None:
    print("Usage: python3 run_tests.py (OPTIONAL: [test_number])")


def validate_test(test_number: int) -> bool:
    global TESTS_LOCATION

    # NOTE: both of these need to be true for a test to be valid
    
    valid_input: bool = os.path.exists(
        f"{TESTS_LOCATION}{test_number}_in.txt"
    )

    valid_output: bool = os.path.exists(
        f"{TESTS_LOCATION}{test_number}_out.txt"
    )

    return valid_input and valid_output


def run_test(
        input_file: str,
        output_file: str,
        test_number: int
) -> None:
    global TESTS_LOCATION
    global DIFFS_LOCATION

    input_test: list[str] = open(f"{TESTS_LOCATION}{input_file}", "r")
    test_name: str = input_test.readline().strip()
    test_command: str = input_test.readline().strip()
    output_data = open(f"{TESTS_LOCATION}{output_file}", "r").read()

    print(f"Running test: {test_name} - {test_number}")

    output = subprocess.getoutput(test_command)

    result = output == output_data

    if not result:
        open(f"{DIFFS_LOCATION}{test_number}_diff.txt", "w").write(
            subprocess.getoutput(
                f"bash -c \"diff <(echo '{output}') <(echo '{output_data}')\""
            )
        )

    print(f"Test: {test_name} - {test_number} - {result}")


def run_single_test(test_number: int) -> None:
    global TESTS_LOCATION

    input_file: str = f"{test_number}_in.txt"
    output_file: str = f"{test_number}_out.txt"

    run_test(input_file, output_file, int(test_number))


def run_all_tests() -> None:
    global TESTS_LOCATION

    files: list = list(sorted(
            os.listdir(TESTS_LOCATION),
            key = lambda x: int(x.split("_")[0])
    ))        

    test_inputs: list = list(filter(
        lambda x: x.endswith("_in.txt"),
        files
    ))

    test_outputs: list = list(filter(
        lambda x: x.endswith("_out.txt"),
        files
    ))

    for test_input, test_output in zip(test_inputs, test_outputs):
        run_test(
            test_input,
            test_output,
            int(test_input.split("_")[0])
        )


def main(test_number: int = None) -> None:
    if test_number is not None:
        if not validate_test(test_number):
            print(f"Error: Test {test_number} does not exist")
            exit(1)

        run_single_test(test_number)
        return
    
    run_all_tests()


if __name__ == "__main__":

    if len(sys.argv) > 2:
        print(f"Error: Too many arguments: {len(sys.argv)}")
        print_help()
        exit(1)

    if len(sys.argv) == 2:
        main(int(sys.argv[1]))
        exit(0)

    main()