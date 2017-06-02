import tkinter as tk
import tkinter.messagebox

from tkinter.constants import *

class App:
	def __init__(self):
		self.root = tk.Tk()
		self.root.title("Title")
		
		#self.list = Tk.Listbox(self.root)
		#self.list.pack(side=LEFT, fill=BOTH, expand=True)
		#self.list.bind("<Double-Button-1>", self.info)
		
		self.panel = tk.Frame(self.root)
		self.panel.pack(side=LEFT)
		
		self.hello_button = tk.Button(self.panel, text="Hello!", command=self.hello)
		self.hello_button.pack(side=LEFT, fill=X)
		
		self.goodbye_button = tk.Button(self.panel, text="Goodbye :(", command=self.root.destroy)
		self.goodbye_button.pack(side=LEFT, fill=X)

	def hello(self):
		tk.messagebox.showinfo("Hello!", "Hello there, beautiful human.")

if __name__ == "__main__":
	app = App().root.mainloop()