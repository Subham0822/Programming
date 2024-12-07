num = []
a = []
b = []
length = int(input("Enter the length of the array: "))
for i in range(0,length):
    x = int(input(f"Enter the {i+1} element: "))
    num.append(x)
for i in range(0,length):
    if num[i]%2 == 0:
        a.append(num[i])
    else:
        b.append(num[i])
print("Even list")
for i in range(0,len(a)):
    print(f"{a[i]}", end=" ")
print("\n")
print("Odd list")
for i in range(0,len(b)):
    print(f"{b[i]}", end=" ")
