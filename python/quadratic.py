import math
a=float(input("Enter the first number: "))
b=float(input("Enter the second number: "))
c=float(input("Enter the third number: "))
print(f"The equation is {a}x^2 + {b}x + {c}")
disc=(b**2)-(4*a*c)
if disc>0:
    root1=((-b)+math.sqrt(disc))/(2*a)
    root2=((-b)-math.sqrt(disc))/(2*a)
    print(f"The first root is {root1}")
    print(f"The second root is {root2}")

elif disc==0:
    root=(-b)/(2*a)
    print(f"The root is {root}")

else:
    real=((-b)/(2*a))
    imag=(math.sqrt(-((b**2)-(4*a*c))))/(2*a)
    real1=round(real,2)
    imag1=round(imag,2)
    print(f"The first root is {real1} + {imag1}i")
    print(f"The second root is {real1} - {imag1}i")
