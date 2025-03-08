import sys

ticket=int(input("Enter number of ticket: "))
if ticket<5 or ticket>40:
    print("Minimum of 5 and Maximum of 40 Tickets")
    sys.exit()
refreshment=input("Do you want refreshment(y/n): ")
if refreshment!="y" and refreshment!="n":
    print("Invalid Input")
    sys.exit()
coupon=input("Do you have coupon code(y/n): ")
if coupon!="y" and coupon!="n":
    print("Invalid Input")
    sys.exit()
circle=input("Enter the circle(k/q): ")
if circle!="k" and circle!="q":
    print("Invalid Input")
    sys.exit()

total=0
if circle=="k":
    total=75*ticket
    total=total-(total*(10/100))
else:
    total=150*ticket
    total=total-(total*(10/100))

if refreshment=="y":
    members=int(input("Refreshments for how many members: "))
    total=total+(members*50)

if coupon=="y":
    total=total-(total*(2/100))

print("Ticket cost: Rupees ",total)


