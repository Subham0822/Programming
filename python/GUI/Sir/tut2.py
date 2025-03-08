from tkinter import *
x_root=Tk() #root is an instance of Tk class#provide basic GUI
#gui logic
#width X height
x_root.geometry("444x234")
x_root.title("My GUI")
# width,height
x_root.minsize(200,100)
#width,height
x_root.maxsize(1200,988)
text1=Label(text="This is my 1st GUI")
text1.pack()
# insert image
photo=PhotoImage(file="1.png")
pic_label=Label(image=photo)
pic_label.pack()
#Important label options:
#text-adds the text
#bg-background
#fg-foreground
#font-sets the font
#padx-x padding
#paddy- y padding
#relif-border styling-SUNKEN,RAISED,GROOVE,RIDGE
title_label=Label(text='''Arab Digest is a partner of Fair Observer that produces\n 
some of the best content on the Middle East and North Africa (MENA).\n 
Russian President Vladimir Putin's invasion of Ukraine...''',bg="green",fg="white",padx=23,pady=44,font=("comicscansms",9))
title_label.pack()
x_root.mainloop()#make interactive keepGUI logics
#widegets and attributes
