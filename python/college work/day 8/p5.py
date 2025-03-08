import re

def validate_password(password):
    errors = []
    if len(password) < 8:
        errors.append("Password must be at least 8 charactyers long.")
    if not re.search(r'[a-z]', password):
        errors.append("Password must contain at least one lowercase letter.")
    if not re.search(r'[A-Z]', password):
        errors.append("Password must contain at least one uppercase letter.")
    if not re.search(r'[0-9]', password):
        errors.append("Password must contain at least one numeral.")
    if not re.search('\W', password):
        errors.append("Password must contain at least one special character.")

    if errors:
        for error in errors:
            print(error)
    else:
        print("Password is valid.")

password = input("Enter a new password: ")
validate_password(password)