from tkinter import *
root=Tk()
def getvals():
    print("Submit Successful")
    print(f"{nameval.get(),phoneval.get(),genderval.get(),e_contactval.get(),pay_modeval.get(),foodservicevar.get()}")
    with open("record.txt","w") as f:
        f.write(f"{nameval.get(),phoneval.get(),genderval.get(),e_contactval.get(),pay_modeval.get(),foodservicevar.get()}\n")
root.geometry("644x344")
#heading
Label(root,text="Welcome to tour and travels",font="comissansms 13 bold",padx=6,pady=15).grid(row=0,column=3)

#text for our form
name=Label(root,text="Name")
phone=Label(root,text="Phone")
gender=Label(root,text="Gender")
e_contact=Label(root,text="Emargency Contact")
pay_mode=Label(root,text="Payment Mode")

#pack text for our form
name.grid(row=1,column=2)
phone.grid(row=2,column=2)
gender.grid(row=3,column=2)
e_contact.grid(row=4,column=2)
pay_mode.grid(row=5,column=2)

#create variables
nameval=StringVar()
phoneval=StringVar()
genderval=StringVar()
e_contactval=StringVar()
pay_modeval=StringVar()
foodservicevar=BooleanVar()

#create entry widget
nameentry=Entry(root,textvariable=nameval)
phoneentry=Entry(root,textvariable=phoneval)
genderentry=Entry(root,textvariable=genderval)
e_contactentry=Entry(root,textvariable=e_contactval)
pay_modeentry=Entry(root,textvariable=pay_modeval)

#packing the entery
nameentry.grid(row=1,column=3)
phoneentry.grid(row=2,column=3)
genderentry.grid(row=3,column=3)
e_contactentry.grid(row=4,column=3)
pay_modeentry.grid(row=5,column=3)
#checkbox
foodservice=Checkbutton(text="Want to prebbok your meals?",variable=foodservicevar)
foodservice.grid(row=6,column=3)
#button and pack
Button(text="Submit",command=getvals).grid(row=7,column=3)
root.mainloop()
