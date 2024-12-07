import sys

class Employee():
    def __init__(self, employeeID, employeeName, employeeAdd, employeePh, basic_salary, hra):
        self.employeeID = employeeID
        self.employeeName = employeeName
        self.employeeAdd = employeeAdd
        self.employeePh = employeePh
        self.basic_salary = basic_salary
        self.hra = hra
        

class Manager(Employee):
    def __init__(self, employeeID, employeeName, employeeAdd, employeePh, basic_salary, hra):
        Employee.__init__(self, employeeID, employeeName, employeeAdd, employeePh, basic_salary, hra)
    def cal_salary(self):
        special_all = self.basic_salary * 0.15
        salary = self.basic_salary + (self.basic_salary * (special_all/100)) + (self.basic_salary * (self.hra/100))
        return salary 
    def display_employee_details(self):
        total_salary = self.cal_salary()
        print(f"ID: {self.employeeID}")
        print(f"Name: {self.employeeName}")
        print(f"Address: {self.employeeAdd}")
        print(f"Contact: {self.employeePh}")
        print(f"Basic Salary: {self.basic_salary}")
        print(f"Total Salary: {total_salary}")

class Trainee(Employee):
    def __init__(self, employeeID, employeeName, employeeAdd, employeePh, basic_salary, hra):
        Employee.__init__(self, employeeID, employeeName, employeeAdd, employeePh, basic_salary, hra)
    def cal_salary(self):
        special_all = self.basic_salary * 0.1
        salary = self.basic_salary + (self.basic_salary * (special_all/100)) + (self.basic_salary * (self.hra/100))
        return salary 
    def display_employee_details(self):
        total_salary = self.cal_salary()
        print(f"ID: {self.employeeID}")
        print(f"Name: {self.employeeName}")
        print(f"Address: {self.employeeAdd}")
        print(f"Contact: {self.employeePh}")
        print(f"Basic Salary: {self.basic_salary}")
        print(f"Total Salary: {total_salary}")
        
desig = input("Enter your designation: ")
if desig != "Manager" and desig != "Trainee":
    print("Invalid designation")
    sys.exit()

employeeID = int(input("Enter the employee ID: "))
employeeName = input("Enter the employee name: ")
employeeAdd = input("Enter the employee address: ")
employeePh = int(input("Enter the employee phone no.: "))
basic_salary = float(input("Enter the employee basic salary: "))
hra = 1000.5

if desig == "Manager":
    employee = Manager(employeeID, employeeName, employeeAdd, employeePh, basic_salary, hra)
    
elif desig == "Trainee":
    employee = Trainee(employeeID, employeeName, employeeAdd, employeePh, basic_salary, hra)
    
employee.display_employee_details()

