number = int(input("Enter a number: "))

def main():
    strong(number)
    
def strong(num):
    sum=0
    digit=num
    while(num!=0):
        remainder=num%10
        sum=sum+fact(remainder)
        num=num//10
    if(digit==sum):
        print("The number is a strong number")
    else:
        print("The number is not a strong number")
    
def fact(x):
    if x==0:
        return 1
    else:
        return x*fact(x-1)

main()
