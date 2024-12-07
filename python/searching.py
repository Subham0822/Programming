num = []
length = int(input("Enter the length of the list: "))
for i in range(0,length):
    x=int(input(f"Enter the {i+1} element: "))
    num.append(x)
number = int(input("Enter the number you want to search: "))
flag = False
for i in range(0,length):
    if num[i] == number:
        print(f"Number found! At position {i+1}")
        flag = True
        break
if flag == False:
    print("Number not found")
