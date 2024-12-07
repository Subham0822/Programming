from tkinter import *
root=Tk()
root.geometry("655x333")
#Func to get values and display them in table
def getvals():
    name=uservalue.get()
    id=idvalue.get()
    print(name)
    print(id)
    table.insert(END, f"{name}\t{id}\n")
#Labels
user=Label(root, text="Name")
user_id=Label(root, text="Registration ID")
user.grid(row=0)
user_id.grid(row=1)
#Entry Fields
uservalue=StringVar()
idvalue=StringVar()
userentry=Entry(root, textvariable=uservalue)
identry=Entry(root, textvariable=idvalue)
userentry.grid(row=0, column=1)
identry.grid(row=1, column=1)
#Button
Button(text="Submit", command=getvals).grid(row=2, columnspan=2)
#Table
table=Text(root, height=10, width=30)
table.grid(row=3, columnspan=2)
table.insert(END, "Name\tRegistration ID\n")
root.mainloop()
