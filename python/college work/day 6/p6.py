def positive_only(func):
    def wrapper(a, b):
        a = max(a, 0)
        b = max(b, 0)
        return func(a, b)
    return wrapper
@positive_only
def add_numbers(a, b):
    return a + b
a, b = -50, 60
print("Without decorator Sum is:", a + b)
print("With decorator Sum is:", add_numbers(a, b))