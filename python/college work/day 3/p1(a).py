def gcd(a, b):
    while b!=0:
        a,b=b,a%b
    print("GCD: ",a)

def main():
    a=int(input("Enter a: "))
    b=int(input("Enter b: "))
    gcd(a,b)

main()