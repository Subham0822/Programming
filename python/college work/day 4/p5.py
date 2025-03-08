class Person:
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender

class Publication:
    def __init__(self, no_rp, no_book, no_art):
        self.no_rp = no_rp
        self.no_book = no_book
        self.no_art = no_art

class Faculty(Person, Publication):
    def __init__(self, name, age, gender, desig, dept, no_rp, no_book, no_art):
        Person.__init__(self, name, age, gender)
        Publication.__init__(self, no_rp, no_book, no_art)
        self.desig = desig
        self.dept = dept

    def display_faculty_info(self):
        print(f"Name of faculty: {self.name}")
        print(f"Age: {self.age}")
        print(f"Gender: {self.gender}")
        print(f"Designation: {self.desig}")
        print(f"Department: {self.dept}")
        print(f"No of research papers published: {self.no_rp}")
        print(f"No of book chapters published: {self.no_book}")
        print(f"No of articles published: {self.no_art}")

# Taking input from the user
name = input("Enter faculty name: ")
age = int(input("Enter faculty age: "))
gender = input("Enter faculty gender: ")
desig = input("Enter faculty designation: ")
dept = input("Enter faculty department: ")
no_rp = int(input("Enter number of research papers published: "))
no_book = int(input("Enter number of book chapters published: "))
no_art = int(input("Enter number of articles published: "))

faculty = Faculty(name, age, gender, desig, dept, no_rp, no_book, no_art)

# Display faculty information
faculty.display_faculty_info()
