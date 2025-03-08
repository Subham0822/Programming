def rotate_list(lst):
    return [lst[-1]] + lst[:-1]

# Testing Q3
L = [64, 82, 31, 88, 84, 24, 50, 34, 48, 31]
print("Original List:", L)
print("List after rotation:", rotate_list(L))