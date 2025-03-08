# Initialize two sets (s1 and s2)
s1 = set(map(int, input("Enter elements for set s1 (separate with space): ").split()))
s2 = set(map(int, input("Enter elements for set s2 (separate with space): ").split()))

# (iii) Ask the user which set operation to carry out
operation = input("Which set operation would you like to perform? (Union, Intersection, Difference, Symmetric difference): ").lower()

# (iv) Perform the selected operation
if operation == 'union':
    result = s1.union(s2)
    print("Union of s1 and s2: ", result)
elif operation == 'intersection':
    result = s1.intersection(s2)
    print("Intersection of s1 and s2: ", result)
elif operation == 'difference':
    result = s1.difference(s2)
    print("Difference of s1 - s2: ", result)
elif operation == 'symmetric difference':
    result = s1.symmetric_difference(s2)
    print("Symmetric difference of s1 and s2: ", result)
else:
    print("Invalid operation selected.")


# output
# Enter elements for set s1 (separate with space): 1 2 3 4 5
# Enter elements for set s2 (separate with space): 3 4 5 6 7 8 89
# Which set operation would you like to perform? (Union, Intersection, Difference, Symmetric difference): intersection
# Intersection of s1 and s2:  {3, 4, 5}