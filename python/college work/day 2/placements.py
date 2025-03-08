cse=int(input("Enter the no of students placed in CSE: "))
ece=int(input("Enter the no of students placed in ECE: "))
mech=int(input("Enter the no of students placed in MECH: "))

if cse<0 or ece<0 or mech<0:
    print("Invalid Input")
else:
    max_placements=-1
    department_placements=[]

    if cse>max_placements:
        max_placements= cse
        department_placements=["CSE"]
    elif cse==max_placements:
        department_placements.append("CSE")

    if ece>max_placements:
        max_placements= ece
        department_placements=["ECE"]
    elif ece==max_placements:
        department_placements.append("ECE")

    if mech>max_placements:
        max_placements= mech
        department_placements=["MECH"]
    elif mech==max_placements:
        department_placements.append("MECH")

    if cse==0 and ece==0 and mech==0:
        print("None of the department has got the highest placement")
    else:
        print("Highest placement")
        for department in department_placements:
            print(department)


