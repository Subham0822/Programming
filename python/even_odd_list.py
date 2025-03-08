num_list=[]
length=int(input("Enter the number of elements you want to insert: "))

for i in range(0, length):
    x=int(input(f"Enter the {i+1}. element: "))
    num_list.append(x)

print("The elements you entered are: ")

for i in range(0,length):
    print(num_list[i], end=" ")

print("\n")
even=0

for i in range(0, length):
    if(num_list[i]%2==0):
        even=even+1

odd=0
odd=length-even

print(f"The number of even values present are: {even}")
print(f"The number of odd values present are: {odd}")
