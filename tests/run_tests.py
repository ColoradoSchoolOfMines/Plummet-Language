import os
import sys
import subprocess

FILE_LOCATION: str = os.path.dirname(__file__) + "/"
TESTS_LOCATION: str = os.path.join(FILE_LOCATION, "test_files/")
DIFFS_LOCATION: str = os.path.join(FILE_LOCATION, "diffs/")


class TestResultObject:
    def __init__(self, test_number: int, test_name: str, result: bool):
        self.test_number = test_number
        self.test_name = test_name
        self.result = result

    def __str__(self):
        return f"{self.test_number} - {self.test_name}"


def print_help() -> None:
    print("Usage: python3 run_tests.py [NOTE: Must be run from project root]")
    print("Options: (only one can be used at a time)")
    print("    help        - Prints this help message")
    print("    example     - Runs the example test")
    print("    test_number - Runs the test with the given number")


def print_failed_tests(
    failed_tests: list[TestResultObject] = []
) -> None:
    if len(failed_tests) == 0:
        print("All tests passed")
        return

    print("Failed tests:")
    for test in failed_tests:
        print(f"    {test}")
    print(f"Total failed tests: {len(failed_tests)}")


def validate_test(test_number: int) -> None:
    # NOTE: both of these need to be true for a test to be valid

    valid_input: bool = os.path.exists(
        f"{TESTS_LOCATION}{test_number}_in.txt"
    )

    valid_output: bool = os.path.exists(
        f"{TESTS_LOCATION}{test_number}_out.txt"
    )

    if not valid_input and not valid_output:
        print(f"Error: Test {test_number} does not exist")
        sys.exit(1)

    if not valid_input:
        print(f"Error: Test {test_number} does not have an input file")
        sys.exit(1)

    if not valid_output:
        print(f"Error: Test {test_number} does not have an output file")
        sys.exit(1)


def run_test(
    input_file: str,
    output_file: str,
    test_number: int
) -> TestResultObject:
    input_test: list[str] = open(f"{TESTS_LOCATION}{input_file}", "r")
    test_name: str = input_test.readline().strip()
    test_command: str = input_test.readline().strip()
    output_data: str = open(f"{TESTS_LOCATION}{output_file}", "r").read()

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

    return TestResultObject(test_number, test_name, result)


def run_example_test() -> None:
    # NOTE: ../ is used as the tests are run from the test_files directory and
    #       the example files are in the parent of that directory

    input_file: str = "../example_in.txt"
    output_file: str = "../example_out.txt"

    test_result: TestResultObject = run_test(
        input_file, output_file, "example"
    )

    print_failed_tests([test_result] if not test_result.result else [])


def run_single_test(test_number: int) -> None:
    input_file: str = f"{test_number}_in.txt"
    output_file: str = f"{test_number}_out.txt"

    test_result: TestResultObject = run_test(
        input_file, output_file, int(test_number)
    )

    print_failed_tests([test_result] if not test_result.result else [])


def run_all_tests() -> None:
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

    failed_tests: list[TestResultObject] = []
    for test_input, test_output in zip(test_inputs, test_outputs):
        test_result: TestResultObject = run_test(
            test_input,
            test_output,
            int(test_input.split("_")[0])
        )

        if not test_result.result:
            failed_tests.append(test_result)

    print_failed_tests(failed_tests)


def main(test_number: int = None) -> None:
    if test_number is not None:
        run_single_test(test_number)
        return
    
    run_all_tests()


if __name__ == "__main__":
    if len(sys.argv) > 2:
        print(f"Error: Too many arguments: {len(sys.argv)}")
        print_help()
        sys.exit(1)

    if len(sys.argv) == 2 and sys.argv[1] == "help":
        print_help()
        sys.exit(0)

    if len(sys.argv) == 2 and sys.argv[1] == "example":
        run_example_test()
        sys.exit(0)

    if len(sys.argv) == 2 and sys.argv[1].isnumeric():
        validate_test(int(sys.argv[1]))
        main(int(sys.argv[1]))
        sys.exit(0)
        
    if len(sys.argv) == 2:
        print(f"Error: Invalid argument: {sys.argv[1]}")
        print_help()
        sys.exit(4)
        
    main()