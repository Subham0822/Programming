class Student:
    college_name = "HITK"
    student_count = 0

    def __init__(self, stdid, name, marks):
        self.stdid = stdid
        self.name = name
        self.marks = marks
        self.average = sum(marks) / len(marks)
        self.grade = self.calculate_grade(self.average)
        Student.student_count += 1

    def calculate_grade(self, average):
        if average >= 90:
            return 'O'
        elif 80 <= average < 90:
            return 'A'
        elif 70 <= average < 80:
            return 'B'
        elif 60 <= average < 70:
            return 'C'
        elif 50 <= average < 60:
            return 'D'
        else:
            return 'F'

    def display_student_info(self):
        marks_str = ' '.join(map(str, self.marks))
        print(f"{self.stdid} {self.name} {marks_str} {self.average:.2f} {self.grade}")

# Taking input from the user
students = []

num_students = int(input("Enter the number of students: "))
for _ in range(num_students):
    stdid = input("Enter student ID: ")
    name = input("Enter student name: ")
    marks = list(map(int, input("Enter marks for three subjects: ").split()))
    students.append(Student(stdid, name, marks))

# Display student information
print(f"College Name: {Student.college_name}")
print(f"Total Number of Students: {Student.student_count}")
print("ID Name Sub1 Sub2 Sub3 Average Grade")
for student in students:
    student.display_student_info()
