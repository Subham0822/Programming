# 10

import math

def tri_area(a=5,b=5,c=5):
    if (a+b>c) and (b+c>a) and (a+c>b):
        if a==b==c:
            print("Equilateral")
        elif a==b or a==c or b==c:
            print("Isosceles")
        else:
            print("Scalene")
        s=(a+b+c)/2
        area=math.sqrt(s*(s-a)*(s-b)*(s-c))
        print("Area: ", round(area,2))
    else:
        print("The sides do not form a triangle")

tri_area()
tri_area(5,5,4)
tri_area(5,6,8)

