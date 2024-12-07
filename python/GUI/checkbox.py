from tkinter import *
import tkinter.messagebox as tmsg
root=Tk()
root.title("Welcome to our Tour and Travels")
root.geometry("656x333")
label=Label(root, text="Welcome to our Tour and Travels")

def getvals():
    print("Submit successfull")
    tmsg.showinfo("You Choose", f"{nameval.get(),phoneval.get(),genderval.get(),e_contactval.get(),pay_modeval.get(),foodserviceval.get()}")
    with open("record.txt","w") as f:
        f.write(f"{nameval.get(),phoneval.get(),genderval.get(),e_contactval.get(),pay_modeval.get(),foodserviceval.get()}\n")

#text for the form
name=Label(root, text="Name")
phone=Label(root, text="Phone no.")
gender=Label(root, text="Gender")
e_contact=Label(root, text="Emergency Contact")
pay_mode=Label(root, text="Payment Mode")

#pack text for form
name.grid(row=1, column=2)
phone.grid(row=2, column=2)
gender.grid(row=3, column=2)
e_contact.grid(row=4, column=2)
pay_mode.grid(row=5, column=2)

#create variables
nameval=StringVar()
phoneval=StringVar()
genderval=StringVar()
e_contactval=StringVar()
pay_modeval=StringVar()
foodserviceval=BooleanVar()

#create entry widget
nameentry=Entry(root, textvariable=nameval)
phoneentry=Entry(root, textvariable=phoneval)
genderentry=Entry(root, textvariable=genderval)
e_contactentry=Entry(root, textvariable=e_contactval)
pay_modeentry=Entry(root, textvariable=pay_modeval)

#packing the entry
nameentry.grid(row=1, column=3)
phoneentry.grid(row=2, column=3)
genderentry.grid(row=3, column=3)
e_contactentry.grid(row=4, column=3)
pay_modeentry.grid(row=5, column=3)

#checkbox
foodservice=Checkbutton(text="Want to pre-book your meals?", variable=foodserviceval)
foodservice.grid(row=6, column=3)
Button(root, text="Submit", command=getvals).grid(row=7, column=3)
root.mainloop()
