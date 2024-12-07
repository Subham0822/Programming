a=int(input("Enter a: "))
b=int(input("Enter b: "))
print(f"a: {a}\nb: {b}")
print(f"Memory location of a: {id(a)}\nMemory location of b: {id(b)}")
a,b=b,a
print(f"a: {a}\nb: {b}")
print(f"Memory location of a: {id(a)}\nMemory location of b: {id(b)}")
