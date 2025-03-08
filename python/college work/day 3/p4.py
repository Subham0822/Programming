import sys

num=int(sys.argv[1])
sum=0
while num!=0:
    rem=num%10
    sum+=rem
    num=num//10
print("Sum: ",sum)