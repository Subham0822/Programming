class InvalidAgeException(Exception):
    "Raised when the input value is less than 18"
    pass
number=18
try:
    input_num=int(input("Enter a number: "))
    if(input_num<number):
        raise InvalidAgeException
    else:
        print("Eligible for vote")
except InvalidAgeException:
    print("Invalid age",Exception)