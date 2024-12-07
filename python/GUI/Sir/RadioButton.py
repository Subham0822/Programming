from tkinter import *
import tkinter.messagebox as tmsg

root=Tk()
root.geometry("455x233")
root.title("Radio Button")
def gen():
    tmsg.showinfo("Youchoose", f"{var.get()} ")
#var=IntVar()
var=StringVar()
var.set("Radio")
Label(root,text="Gender",justify=LEFT,padx=14).pack(anchor="w")
#radio=Radiobutton(root,text="Male",padx=14,variable=var,value=1).pack(anchor="w")
#radio=Radiobutton(root,text="Female",padx=14,variable=var,value=2).pack(anchor="w")
radio=Radiobutton(root,text="Male",padx=14,variable=var,value="male").pack(anchor="w")
radio=Radiobutton(root,text="Female",padx=14,variable=var,value="Female").pack(anchor="w")
Button(text="Select",command=gen).pack(anchor="w")
root.mainloop()