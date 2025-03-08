class Employee:
    num_employees = 0

    def __init__(self, name, designation, salary):
        self.name = name
        self.designation = designation
        self.salary = salary
        Employee.num_employees += 1

    def display_employee_info(self):
        print(f"Name: {self.name}, Designation: {self.designation}, Salary: {self.salary}")

# Taking input from the user
employees = []

num_employees = int(input("Enter the number of employees: "))
for _ in range(num_employees):
    name = input("Enter employee name: ")
    designation = input("Enter employee designation: ")
    salary = float(input("Enter employee salary: "))
    employees.append(Employee(name, designation, salary))

# Display employee information
for employee in employees:
    employee.display_employee_info()

# Display total number of employees
print(f"Total number of employees: {Employee.num_employees}")
