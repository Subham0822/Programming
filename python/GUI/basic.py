from tkinter import *
x_root=Tk()
x_root.minsize(200,100)
x_root.maxsize(200,100)
text1=Label(text="This is my 1st GUI")
text1.pack()
def hello():
    print("Hello Tkinter button")
def name():
    print("Subham")
frame=Frame(x_root,borderwidth=6,bg="red",relief=SUNKEN)
frame.pack(side=LEFT,anchor="nw")
b1=Button(frame,fg="red",text="Print",command=hello)
b1.pack(side=LEFT,pady=23)
b2=Button(frame,fg="green",text="Name",command=name)
b2.pack(side=LEFT,pady=23)
x_root.mainloop()
