def count_lines_with_keywords(file_path):
    count = 0
    with open(file_path, 'r') as file:
        for line in file:
            if 'def' in line or 'for' in line:
                count += 1
    return count


file_path = input("Enter the path of the .py file: ")
print("Number of lines containing 'def' or 'for':", count_lines_with_keywords(file_path))