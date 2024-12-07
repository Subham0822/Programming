L = list(map(int, input("Enter the list elements (separate with space): ").split()))

# Sort the list using a key that calculates abs(n-50)
sorted_list = sorted(L, key=lambda x: abs(x-50))
print("List sorted based on abs(n-50):", sorted_list)

# output
# Enter the list elements (separate with space): 4 3 2 5 67
# List sorted based on abs(n-50): [67, 5, 4, 3, 2]