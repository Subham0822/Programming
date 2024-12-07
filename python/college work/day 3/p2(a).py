def factorial(num):
    if num<0:
        return "Factorial of negative numbers is not defined"
    result=1
    for i in range(0, num):
        result*=num
        num-=1
    return result

def main():
    number=int(input("Enter number: "))
    print(f"Factorial of {number}: ",factorial(number))

main()