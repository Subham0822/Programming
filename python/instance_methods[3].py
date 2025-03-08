class Student:
    univ="MAKUT"
    def __init__(self,m1,m2,m3):
        self.m1=m1
        self.m2=m2
        self.m3=m3
    def avg(self):
        return (self.m1+self.m2+self.m3)/3
    @classmethod
    def info1(self):
        return self.univ
    @staticmethod
    def info():
        print("Hello")

s1=Student(34,67,32)
s2=Student(85,32,12)
print(s1.avg())
print(s2.avg())
print(Student.info1())
Student.info()
