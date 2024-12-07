name = input("Enter your name: ")
name = name.title().strip()
id_no = int(input("Enter your id no. "))
unit = float(input("Enter the number of units used: "))
print(f"\nDetails of the consumer:\nName: {name}\nID: {id_no}\nUnit Consumed: {unit}\n")
if unit<=199:
    charge = float(unit * 1.20)

elif unit>=200 and unit<400:
    charge = float(unit * 1.50)

elif unit>=400 and unit<600:
    charge = float(unit * 1.80)

else:
    charge = float(unit * 2.0)

if(charge<100):
    print("Electricity bill is 100")
elif(charge>400):
    surCharge=charge*0.15
    total_amount=charge+surCharge
else:
    total_amount=charge
print("You have to pay:",total_amount)
