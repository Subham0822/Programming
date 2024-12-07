import math
x1=int(input("What's the x coordinate of first point: "))
y1=int(input("What's the y coordinate of the first point : "))
x2=int(input("What's the x coordinate of the second point: "))
y2=int(input("What's the y coordinate of the second point: "))
z=pow((x2-x1), 2)+pow((y2-y1),2)
a=math.sqrt(z)
print(a)
