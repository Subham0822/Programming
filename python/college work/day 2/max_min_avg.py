a=int(input("Enter a: "))
b=int(input("Enter b: "))
c=int(input("Enter c: "))

#for maximum
if a>b and a>c:
    print("Maximum: ",a)
elif b>a and b>c:
    print("Maximum: ",b)
else:
    print("Maximum: ",c)

#for minimum
if a<b and a<c:
    print("Minimum: ",a)
elif b<a and b<c:
    print("Minimum: ",b)
else:
    print("Minimum: ",c)

avg=(float(a)+float(b)+float(c))/3
print("Average: ",avg)
