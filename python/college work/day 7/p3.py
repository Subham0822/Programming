def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

L = list(map(int, input("Enter the list elements (separate with space): ").split()))

for num in L:
    if is_prime(num):
        print(f"First prime number in the list is: {num}")
        break
else:
    print("No prime number found in the list.")


# output
# Enter the list elements (separate with space): 4 3 2 1 7 13 11
# First prime number in the list is: 3