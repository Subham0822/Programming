class A:
    def feature1(self):
        print("feature 1")
    def feature2(self):
        print("feature 2")
class B(A):
    def feature3(self):
        print("feature 3")
    def feature4(self):
        print("feature 4")
class C(B):
    def feature5(self):
        print("feature5")
    def feature6(self):
        print("feature6")
obj=C()
obj.feature1()
obj.feature2()
obj.feature3()
obj.feature4()
obj.feature5()
obj.feature6()
