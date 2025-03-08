maths = int(input("Enter the number obtained in Mathematics: "))
phy = int(input("Enter the number obtained in Physics: "))
chem = int(input("Enter the number obtained in Chemistry: "))
total_3 = int(maths + phy + chem)
total_2 = int(maths + phy)
if (maths>=65 and phy>=55 and chem>=50 and total_3>=190)or total_2>=140:
    
    print("The candidate is elgible.")
else:
    print("The candidate is not elgible.")
