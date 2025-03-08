n = int(input("Enter the number of elements in the list: "))
L = [int(input(f"Enter element {i+1}: ")) for i in range(n)]
element_to_find = int(input("Enter the element to find multiple occurrences: "))

indices = [i for i, x in enumerate(L) if x == element_to_find]
if len(indices) > 1:
    print(f"Indices where {element_to_find} occurred multiple times: {indices}")
else:
    print(f"{element_to_find} does not occur multiple times.")


# output
# nter the number of elements in the list: 4
# Enter element 1: 2
# Enter element 2: 2
# Enter element 3: 3
# Enter element 4: 5
# Enter the element to find multiple occurrences: 2
# Indices where 2 occurred multiple times: [0, 1]