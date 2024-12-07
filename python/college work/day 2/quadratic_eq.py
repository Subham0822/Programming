# Get coefficients a, b, and c from the user
a = float(input("Enter the coefficient of x^2: "))
b = float(input("Enter the coefficient of x: "))
c = float(input("Enter the constant term: "))

# Calculate the discriminant
D = b**2 - 4*a*c

# Determine the roots based on the discriminant
if D > 0:
    # Real and distinct roots
    root1 = (-b + D**0.5) / (2*a)
    root2 = (-b - D**0.5) / (2*a)
    print("Roots are real and distinct")
    print(f"Root 1 is {root1} Root 2 is {root2}")
elif D == 0:
    # Real and equal roots
    root = -b / (2*a)
    print("Roots are real and equal")
    print(f"Root 1 is {root} Root 2 is {root}")
else:
    # Complex conjugate roots
    real_part = -b / (2*a)
    imaginary_part = (-D)**0.5 / (2*a)
    print("Roots are imaginary")
    print(f"Root 1 is {real_part} +i {imaginary_part}")
    print(f"Root 2 is {real_part} -i {imaginary_part}")
