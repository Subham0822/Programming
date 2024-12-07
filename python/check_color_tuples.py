def isElement(tup, element):
    for tupl in tup:
        if element in tupl:
            return True
    return False

tup = (('Red', 'White', 'Blue'), ('Green', 'Pink', 'Purple'), ('Orange', 'Yellow', 'Lime'))

element = 'White'
print(f"Check if {element} present in said tuple of tuples:",isElement(tup, element))

element = 'Olive'
print(f"Check if {element} present in said tuple of tuples:",isElement(tup, element))
