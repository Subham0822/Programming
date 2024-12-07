def count_letters(s):
    letter_count = {}
    for char in s:
        if char in letter_count:
            letter_count[char] += 1
        else:
            letter_count[char] = 1
    return letter_count

string_input = input("Enter a string: ")
print(count_letters(string_input))