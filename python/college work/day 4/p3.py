class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"({self.x},{self.y})"

    def __add__(self, other):
        return Point(round(self.x + other.x), round(self.y + other.y))

    def __sub__(self, other):
        return Point(round(self.x - other.x), round(self.y - other.y))

    def __mul__(self, value):
        return Point(round(self.x * value), round(self.y * value))

    def __truediv__(self, value):
        return Point(round(self.x / value), round(self.y / value))

    def __floordiv__(self, value):
        return Point(self.x // value, self.y // value)

    def __pow__(self, power):
        return Point(round(self.x ** power), round(self.y ** power))

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __lt__(self, other):
        return self.x < other.x and self.y < other.y

    def __le__(self, other):
        return self.x <= other.x and self.y <= other.y

    def __gt__(self, other):
        return self.x > other.x and self.y > other.y

# Taking input from the user for the first point
x1 = float(input("Enter x-coordinate for the first point: "))
y1 = float(input("Enter y-coordinate for the first point: "))
p1 = Point(round(x1), round(y1))

# Taking input from the user for the second point
x2 = float(input("Enter x-coordinate for the second point: "))
y2 = float(input("Enter y-coordinate for the second point: "))
p2 = Point(round(x2), round(y2))

# Displaying the points
print(f"The first object is: {p1}")
print(f"The second object is: {p2}")

# Performing and displaying various operations
print(f"The sum of {p1} and {p2} is {p1 + p2}")
print(f"The difference of {p1} and {p2} is {p1 - p2}")

# Taking a value from the user for multiplication, division, and other operations
value = float(input("Enter a value for multiplication and division operations: "))
print(f"The product of {p1} and {value} is {p1 * value}")
print(f"The division of {p1} and {value} is {p1 / value}")
print(f"The integer division of {p1} and {value} is {p1 // value}")
print(f"The modulus of {p1} and {value} is {Point(round(p1.x % value), round(p1.y % value))}")

# Taking a power value from the user for exponentiation
power = int(input("Enter a power value: "))
print(f"The power of {p2} to the {power} is {p2 ** power}")

# Displaying comparison results
print(f"{p1} == {p2} is {p1 == p2}")
print(f"{p1} >= {p2} is {p1 >= p2}")
print(f"{p1} <= {p2} is {p1 <= p2}")
print(f"{p1} > {p2} is {p1 > p2}")
print(f"{p1} < {p2} is {p1 < p2}")
