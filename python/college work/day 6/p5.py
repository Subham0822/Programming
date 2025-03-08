from functools import reduce
def divisible_by_3_and_5(lst):
    return list(filter(lambda x: x % 3 == 0 and x % 5 == 0, lst))
def square_numbers(lst):
    return list(map(lambda x: x ** 2, lst))
def product_of_numbers(lst):
    return reduce(lambda x, y: x * y, lst)
L = list(range(21))
print("List is:", L)
print("The numbers divisible by both 3 and 5 are:", divisible_by_3_and_5(L))
print("Square Numbers in list:", square_numbers(L))
user_input = [12, 2, 3, 4, 5]
print("List is:", user_input)
print("Product of all numbers:", product_of_numbers(user_input))
