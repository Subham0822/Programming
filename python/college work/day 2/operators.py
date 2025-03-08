import sys

if len(sys.argv)!=3 or len(sys.argv)>3:
    print("Usage error")
    exit(1)

a=int(sys.argv[1])
b=int(sys.argv[2])
ls=[a,b]

print(f"Relational Operators:\n<\t: {a<b}\n==\t: {a==b}\n!=\t: {a!=b}\n>\t: {a>b}\n>=\t: {a>=b}\n<=\t: {a<=b}")
print(f"Identity Operators:\nis\t: {a is b}\nis not\t: {a is not b}")
print(f"Membership Operators:\nin for a\t: {a in ls}\nin for b\t: {b in ls}\nnot in for a\t: {a not in ls}\nnot in for b\t: {b not in ls}")
