# (i) Print the value of a dictionary item for the specific key.
# (ii) Add an item to a dictionary by assigning a value to a new key.
# (iii) Remove an element from a dictionary.
# (iv) Change the value of a dictionary element by referring to its key.
# (v) Iterate through dictionary keys one by one.
# (vi) Find the length of the dictionary.

# Creating a dictionary with key-value pairs
my_dict = {'name': 'John', 'age': 25, 'city': 'New York'}

# (i) Print the value for a specific key
key = input("Enter the key to get the value: ")
print(f"Value for key '{key}': {my_dict.get(key, 'Key not found')}")

# (ii) Add a new item to the dictionary
new_key = input("Enter a new key to add to the dictionary: ")
new_value = input(f"Enter the value for key '{new_key}': ")
my_dict[new_key] = new_value
print("Updated dictionary: ", my_dict)

# (iii) Remove an element from the dictionary
remove_key = input("Enter the key of the element you want to remove: ")
my_dict.pop(remove_key, None)
print("Dictionary after removal: ", my_dict)

# (iv) Change the value of a dictionary element
change_key = input("Enter the key whose value you want to change: ")
new_value = input(f"Enter the new value for key '{change_key}': ")
my_dict[change_key] = new_value
print("Dictionary after value change: ", my_dict)

# (v) Iterate through dictionary keys
print("Dictionary keys: ")
for k in my_dict:
    print(k)

# (vi) Find the length of the dictionary
print(f"Length of the dictionary: {len(my_dict)}")



# output

# Enter the key to get the value: age
# Value for key 'age': 25
# Enter a new key to add to the dictionary: dob
# Enter the value for key 'dob': 2nd july 2005
# Updated dictionary:  {'name': 'John', 'age': 25, 'city': 'New York', 'dob': '2nd july 2005'}
# Enter the key of the element you want to remove: name
# Dictionary after removal:  {'age': 25, 'city': 'New York', 'dob': '2nd july 2005'}
# Enter the key whose value you want to change: city 
# Enter the new value for key 'city': Kolkata    
# Dictionary after value change:  {'age': 25, 'city': 'Kolkata', 'dob': '2nd july 2005'}
# Dictionary keys: 
# age
# city
# dob
# Length of the dictionary: 3