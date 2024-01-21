class Result:
    def __init__(self, value, success):
        self.value = value
        self.success = success

    def unwrap(self, error_message = ""):
        if self.success: return self.value
        raise RuntimeError(error_message)
    
    def execute_on_error(self, error_function):
        if self.success: return self.value
        error_function(self.value)