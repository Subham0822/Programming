def singleElement(my_set, element):
    my_set.add(element)
    return my_set

def multiElement(my_set, elements):
    my_set.update(elements)
    return my_set

def removeElement(my_set, element):
    my_set.remove(element)
    return my_set

my_set = {1,5,2,6}

element= int(input("Enter the element you want to enter: "))
my_set = singleElement(my_set, element)
print("Set after adding a single element:", my_set)

elements = {5, 6, 7}
my_set = multiElement(my_set, elements)
print("Set after adding multiple elements:", my_set)

element1= int(input("Enter the element you want to delete: "))
my_set = removeElement(my_set, element1)
print("Set after deleting an element:", my_set)
