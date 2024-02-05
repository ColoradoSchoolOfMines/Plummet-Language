import sys

class Result:
    def __init__(self, value, success):
        self.value = value
        self.success = success

    def unwrap(self, error_message, exit_code = 1):
        if self.success: return self.value
        print(error_message)
        sys.exit(exit_code)