import math

def gcd(number):
    if len(number)==0:
        return None
    result=number[0]
    for i in range(1, len(number)):
        result=math.gcd(result, number[i])
    return result
def main():
    number=[]
    size=int(input("How many value you want to enter: "))
    for i in range(0,size):
        num=int(input("Enter value: "))
        number.append(num)
    print("GCD: ",gcd(number))

main()