import tkinter as tk
import tkinter.messagebox
import tkinter.scrolledtext 

from tkinter.constants import *

def eeprom_strings(file_name):
	f = open(file_name, "rb")
	
	#read beginning two bytes (skip 2)
	f.read(2)
	#get rest of data in file
	f_data = f.read()
	#find the end of file
	index = f_data.index(0b11111111)
	#slice off trailing values and update f_data
	f_data = f_data[:index]
	#parse
	lst = f_data.split(b"\x00")
	return b"\n".join(lst).decode("ascii")

class App:
	def __init__(self):
		self.root = tk.Tk() #first create root widget, bare window
		self.root.title("Title")
		tk.Label(self.root, text="Hephaestus").pack() #main window header
		#logo header
		#logo = tk.PhotoImage(file="logo.png")
		#tk.Label(self.parent, image=logo).photo.pack()
		
		#self.list = Tk.Listbox(self.root)
		#self.list.pack(side=LEFT, fill=BOTH, expand=True)
		#self.list.bind("<Double-Button-1>", self.info)
		
		self.panel = tk.Frame(self.root)
		self.panel.pack(side=LEFT)
		
		#Hello button
		self.hello_button = tk.Button(self.panel, text="Hello!", command=self.hello)
		self.hello_button.pack(side=LEFT, fill=X)
		
		#Goodbye button
		self.goodbye_button = tk.Button(self.panel, text="Goodbye :(", command=self.root.destroy)
		self.goodbye_button.pack(side=LEFT, fill=X)

		#eeprom strings scroll window
		self.eeprom_scroll = tk.scrolledtext.ScrolledText()
		self.eeprom_scroll.pack()
		self.eeprom_scroll.insert(INSERT, eeprom_strings("eeprom_dump.hex"))

	def hello(self):
		tk.messagebox.showinfo("Hello!", "Hello there, beautiful human.")

if __name__ == "__main__":
	app = App().root.mainloop()

