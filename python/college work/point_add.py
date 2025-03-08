class Point():
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def __add__(self):
        print(self.a + self.b)
        
P1 = Point(10, 15)
P1.__add__()
