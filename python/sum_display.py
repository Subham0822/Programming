from tkinter import *
x_root = Tk()
x_root.minsize(200, 100)
x_root.maxsize(1200, 988)
a = 10
b = 15
text1 = Label(text = "This is for sum display")
text1.pack()
def displaySum():
    print(10+15)
frame = Frame(x_root, borderwidth = 6, bg = "red", relief = SUNKEN)
frame.pack(side = LEFT, anchor = "nw")
b1 = Button(frame, fg = "blue", text = "Print", command = displaySum)
b1.pack(side = LEFT, pady = 23, padx = 23)
x_root.mainloop()
