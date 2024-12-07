def convert(tup):
    try:
        dictionary = dict(tup)
        return dictionary
    except TypeError:
        return "Tuple must contain key-value pairs."

tup = (('a', 1), ('b', 2), ('c', 3))
result = convert(tup)
print("Converted dictionary:", result)
