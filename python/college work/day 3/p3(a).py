def fibonacci(n):
    a=0
    b=1
    print(f"{a}\n{b}")
    for i in range(n-2):
        print(a+b)
        a,b=b,(a+b)
    
def main():
    range=int(input("Enter range: "))
    fibonacci(range)

main()