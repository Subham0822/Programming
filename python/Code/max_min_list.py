num=[]
length=int(input("Enter the number of elements you want to insert: "))

for i in range(0, length):
    x=int(input(f"Enter the {i+1}. element: "))
    num.append(x)

print("The elements you entered are: ")

for i in range(0,length):
    print(num[i], end=" ")

print("\n")

max=num[0]
min=num[0]

for i in range(0,length):
    if(num[i]>max):
        max=num[i]
    elif(num[i]<min):
        min=num[i]

print(f"The max element present: {max}")
print(f"The min element present: {min}")

