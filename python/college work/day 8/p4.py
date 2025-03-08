def replace_and_copy_lines(source_file, dest_file):
    with open(source_file, 'r') as src, open(dest_file, 'w') as dest:
        for line in src:
            if line.startswith('This'):
                dest.write(line.replace('This', 'That'))

replace_and_copy_lines('/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/Python/day8/test.txt', '/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/Python/day8/dest.txt')
print("Lines starting with 'This' have been copied to 'dest.txt' with substitutions.")