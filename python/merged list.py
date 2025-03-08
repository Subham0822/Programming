list1=[]
list2=[]
length1=int(input("Enter the length of the first list: "))

for i in range(0,length1):
    x=int(input(f"Enter the {i+1}. element: "))
    list1.append(x)

for i in range(0,len(list1)):
    print(f"{list1[i]}", end=" ")

print("\n")

length2=int(input("Enter the length of the second list: "))

for i in range(0,length2):
    x=int(input(f"Enter the {i+1}. element: "))
    list2.append(x)

for i in range(0,len(list2)):
    print(f"{list2[i]}", end=" ")

print("\n")

print(f"The merged list is: {list1+ list2}", end=" ")
