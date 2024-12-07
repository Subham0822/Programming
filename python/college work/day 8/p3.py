import re

txt = 'Hello hello students of AIML 2024'

lowercase_am = re.findall(r'[a-m]', txt)
print("Lowercase letters between 'a' and 'm':", sorted(set(lowercase_am)))

lowercase_not_am = re.findall(r'[n-z]', txt)
print("Lowercase letters excluding 'a' to 'm':", sorted(set(lowercase_not_am)))

digits = re.findall(r'\d',txt)
print("Digit characters:", digits)

pattern1 = re.findall(r'he..o', txt)
print('Pattern starting with "he", followed by two characters, and an "o":', pattern1)

pattern2 = re.findall(r'he.*o', txt)
print('Pattern starting with "he", followed by 0 or more characters, and an "o":', pattern2)

pattern3 = re.findall(r'He.+o', txt)
print('Pattern starting with "He", followed by 1 or more characters, and an "o":', pattern3)

pattern4 = re.findall(r'He..o', txt)
print('Pattern starting with "He", followed by exactly 2 characters, and an "o":', pattern4)