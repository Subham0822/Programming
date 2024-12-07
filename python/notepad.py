from tkinter import *
from tkinter.messagebox import showinfo
from tkinter.filedialog import askopenfilename, asksaveasfilename
import os
root=Tk()
def newFile():
    global file
    root.title("untitled - Notepad")
    file=None
    TextArea.delete(1.0, END)
def openFile():
    global file
    file=askopenfilename(defaultextension=".txt", filetypes=[("All Files", "*.*"),("Text Documents","*.txt")])
    if file=="":
        file=None
    else:
        root.title(os.path.basename(file)+" -Notepad")
        TextArea.delete(1.0, END)
        f=open(file, "r")
        TextArea.insert(1.0, f.read())
        f.close()
def saveFile():
    global file
    if file==None:
        file=asksaveasfilename(initialfile='Untitled.txt', defaultextension=".txt", filetypes=[("All Files", "*.*"),("Text Documents", "*.txt")])
        if file=="":
            file=None
        else:
            f=open(file,"w")
            f.write(TextArea.get(1.0,END))
            f.close()
            root.title(os.path.basename(file)+" -Notepad")
    else:
        f=open(file, "w")
        f.write(TextArea.get(1.0, END))
        f.close()

def cut():
    TextArea.event_generate(("<<Cut>>"))
def copy():
    TextArea.event_generate(("<<Copy>>"))
def paste():
    TextArea.event_generate(("<<Paste>>"))
def about():
    showinfo("Notepad","This is my notepad")
def quitApp():
    root.destroy()

root.title("untitled - Notepad")
root.wm_iconbitmap("notepadicon.ico")
root.geometry("644x788")
TextArea=Text(root, font="lucia 13")
file=None
TextArea.pack(expand=True, fill=BOTH)
#create MenuBar
Menubar=Menu(root)
#start of file menu
FileMenu=Menu(Menubar, tearoff=0)
#to open new file
FileMenu.add_command(label="New", command=newFile)
#to open existing file
FileMenu.add_command(label="Open", command=openFile)
#to save the current file
FileMenu.add_command(label="Save", command=saveFile)
FileMenu.add_separator()
FileMenu.add_command(label="Exit", command=quitApp)
Menubar.add_cascade(label="File", menu=FileMenu)

#edit menu starts
EditMenu=Menu(Menubar, tearoff=0)
#features of copy, cut, paste
EditMenu.add_command(label="Cut", command=cut)
EditMenu.add_command(label="Copy", command=copy)
EditMenu.add_command(label="Paste", command=paste)
Menubar.add_cascade(label="Edit", menu=EditMenu)
#edit menu ends

#help menu starts
HelpMenu=Menu(Menubar, tearoff=0)
HelpMenu.add_command(label="About", command=about)
Menubar.add_cascade(label="Help", menu=HelpMenu)
#help menu ends

root.config(menu=Menubar)

#adding scrollbar
scrollbar=Scrollbar(TextArea)
scrollbar.pack(side=RIGHT, fill=Y)
scrollbar.config(command=TextArea.yview)
TextArea.config(yscrollcommand=scrollbar.set)

root.mainloop()
