from tkinter import *
import tkinter.messagebox as tmsg
root=Tk()
root.geometry("455x233")
root.title("Slider")
def getrupees():
    print(f"we have creited {myslider2.get()} rupess to your bank ac")
    tmsg.showinfo("Amount credited!",f"we have creited {myslider2.get()} rupess to your bank ac")
#myslider1=Scale(root, from_=0,to=100)
#myslider1.pack()
Label(root,text="How many rupees do you want ?").pack()
myslider2=Scale(root, from_=0,to=100,orient=HORIZONTAL,tickinterval=50)
#myslider2.set(30)
myslider2.pack()
Button(root,text="Get Rupess",pady=10,command=getrupees).pack()
root.mainloop()