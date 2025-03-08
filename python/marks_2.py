roll = int(input("Input your roll no. "))
name = input("Input your name: ")
name = name.strip().title()
phy = int(input("Enter yor marks in Physics: "))
maths = int(input("Enter yor marks in Mathematics: "))
chem = int(input("Enter yor marks in Chemistry: "))
total = phy + maths + chem
percentage = float((total/300.0)*100.0)
print(f"Student's roll number is {roll} and name is {name}")
if percentage<0 or percentage>100:
    print("Marks entered are not valid.")

elif percentage>90 and percentage<=100:
    print("Your division is O")

elif percentage>80 and percentage<=90:
    print("Your division is E")

elif percentage>70 and percentage<=80:
    print("Your divison is A")

elif percentage>60 and percentage<=70:
    print("Your divison is B")

elif percentage>50 and percentage<=60:
    print("Your divison is C")

elif percentage>40 and percentage<=50:
    print("Your divison is D")

else:
    print("Your division is F")

