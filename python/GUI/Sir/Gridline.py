from tkinter import *
root=Tk()
root.geometry("655x333")
def getvals():
    print(uservalue.get())
    print(passvalue.get())
user=Label(root,text="Username")
password=Label(root,text="Password")
user.grid()
password.grid(row=1)
#variable classes in tkinter
# BooleanVar, DoubleVar,IntVar,StringVar
uservalue=StringVar()
passvalue=StringVar()
userentry=Entry(root,textvariable=uservalue)
passentery=Entry(root,textvariable=passvalue)
userentry.grid(row=0,column=1)
passentery.grid(row=1,column=1)
Button(text="submit",command=getvals).grid()
root.mainloop()