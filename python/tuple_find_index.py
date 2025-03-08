def getIndex(tup, item):
    try:
        index = tup.index(item)
        return index
    except ValueError:
        return "Item not found in the tuple."

tup = (10, 20, 30, 40, 50)
item = int(input("Enter the element: "))
result = getIndex(tup, item)
print("The index of the item is:", result)
