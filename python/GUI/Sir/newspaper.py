from tkinter import *
root=Tk()
root.geometry("655x333")
root.maxsize(1250,1000)
root.minsize(600,500)
f1=Frame(root,bg="gray",borderwidth=6,relief=SUNKEN)
f1.pack(side=LEFT,fill="y")
f2=Frame(root,borderwidth=8,bg="gray",relief=SUNKEN)
f2.pack(side=TOP,fill="x")
l=Label(f1,text="Project GUI-Pycharm")
l.pack(pady=142)
l1=Label(f2,text="Welcome to Pycharm",font="Helvetica 16 bold",fg="red")
l1.pack()
root.mainloop()