lst=[]
num=int(input("Number of elements: "))
for i in range(0,num):
    x=int(input("Enter the elements"))
    lst.append(x)

for i in range(0,num):
    print(lst[i],end=" ")
