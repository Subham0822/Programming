import random
L = [random.randint(1, 9) for _ in range(20)]
print("Original List:", L)
def unique(lst):
    result = []
    for item in lst:
        if lst.count(item) == 1:
            result.append(item)
    return result
def duplicate(lst):
    result = {}
    for item in lst:
        count = lst.count(item)
        if count > 1 and item not in result:
            result[item] = count
    return result
def createuniq(lst):
    return list(set(lst))
print("Unique elements are:", unique(L))
print("Duplicate elements are:", duplicate(L))
print("List of Unique elements:", createuniq(L))