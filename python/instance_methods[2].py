class Student():
    def __init__(self, m1, m2, m3):
        self.m1=m1
        self.m2=m2
        self.m3=m3
    def avg(self):
        return (self.m1+self.m2+self.m3)/3
    def get_m1(self):
        return self.m1
    def set_m1(self,value):
        self.m1=value
s1=Student(45,55,65)
s2=Student(75,85,95)
s1.set_m1(90)
print(s1.get_m1())
print(s1.avg())
print(s2.avg())
