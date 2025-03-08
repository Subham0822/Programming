def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

def main():
    a=int(input("Enter a: "))
    b=int(input("Enter b: "))
    result=gcd(a,b)
    print("GCD: ",result)
        
main()