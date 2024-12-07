from tkinter import *
root=Tk()
root.geometry("655x333")
def hello():
    print("hello tkinter Buttons")
def name():
    print("Nilanjan")
frame=Frame(root,borderwidth=6,bg="grey",relief=SUNKEN)
frame.pack(side=LEFT,anchor="nw")
b1=Button(frame,fg="red",text="Print",command=hello)
b1.pack(side=LEFT,pady=23)
b2=Button(frame,fg="green",text="Name",command=name)
b2.pack(side=LEFT,pady=23)
root.mainloop()