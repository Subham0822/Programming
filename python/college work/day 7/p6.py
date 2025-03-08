# First list contains roll numbers from 1 to 25
roll_numbers = list(range(1, 26))

# Second list reads names from a file (assuming each name is on a new line)
file_path = input("Enter the file path containing the names: ")
with open(file_path, 'r') as file:
    names = [line.strip() for line in file]

# Combine the two lists into a dictionary
if len(roll_numbers) == len(names):
    student_dict = dict(zip(roll_numbers, names))
    print("Dictionary of Roll Numbers and Names:", student_dict)
else:
    print("Mismatch in number of roll numbers and names.")


# output
# Enter the file path containing the names: /Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/Python/day7/names_list.txt
# Dictionary of Roll Numbers and Names: {1: 'John', 2: 'Emily', 3: 'Michael', 4: 'Sarah', 5: 'David', 6: 'Jessica', 7: 'James', 8: 'Ashley', 9: 'Robert', 10: 'Amanda', 11: 'William', 12: 'Melissa', 13: 'Christopher', 14: 'Nicole', 15: 'Joseph', 16: 'Elizabeth', 17: 'Andrew', 18: 'Heather', 19: 'Matthew', 20: 'Megan', 21: 'Daniel', 22: 'Stephanie', 23: 'Anthony', 24: 'Kimberly', 25: 'Joshua'}