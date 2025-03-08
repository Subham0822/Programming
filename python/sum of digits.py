number = int(input("Enter a number: "))
sum=0
while (number!=0):
    remainder=number%10
    sum+=remainder
    number=number//10

print(f"The sum of digits is {sum}")
