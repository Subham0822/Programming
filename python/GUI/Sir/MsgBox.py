from tkinter import *
import tkinter.messagebox as tmsg
root=Tk()
root.geometry("733x566")
root.title("Pycharm")
def myfunc():
    print("this is my menu")
def help():
    print("I will help you")
    tmsg.showinfo("Help","I will help you")
def rate():
    value=tmsg.askquestion("Share experience","How was your Experience(Good?)")
    print(value)
    if value=="yes":
        msg="Rate us on app store"
    else:
        msg="Tell us what went wrong"
    tmsg.showinfo("Experience",msg)
mainmenu=Menu(root)
m1=Menu(mainmenu,tearoff=0)
m1.add_command(label="New Project",command=myfunc)
m1.add_command(label="Save",command=myfunc)
m1.add_separator()
m1.add_command(label="Save As",command=myfunc)
m1.add_command(label="Print",command=myfunc)
mainmenu.add_cascade(label="File",menu=m1)
root.config(menu=mainmenu)
#for edit menu
m2=Menu(mainmenu,tearoff=0)
m2.add_command(label="Cut",command=myfunc)
m2.add_command(label="Copy",command=myfunc)
m2.add_separator()
m2.add_command(label="Paste",command=myfunc)
m2.add_command(label="Delete",command=myfunc)
mainmenu.add_cascade(label="Edit",menu=m2)
root.config(menu=mainmenu)
#helping menu
m3=Menu(mainmenu,tearoff=0)
m3.add_command(label="Help",command=help)
m3.add_command(label="Rate Us",command=rate)
mainmenu.add_cascade(label="Help",menu=m3)
root.config(menu=mainmenu)
root.mainloop()