

import tkinter as tk
from tkinter import Menu
# Function to handle the button click event
def on_button_click():
    label.config(text="Hello, " + name_entry.get())
# Create the main application window
app = tk.Tk()
app.title("Redesigned Python GUI")
label = tk.Label(app, text="Welcome to the Redesigned GUI")  # Create a label widget
label.pack(pady=10)
name_entry = tk.Entry(app)    # Create an entry field to input a name
name_entry.pack()
# Create a button to trigger an action
button = tk.Button(app, text="Greet", command=on_button_click)
button.pack()
# Create a checkbox
checkbox_var = tk.IntVar()
checkbox = tk.Checkbutton(app, text="Enable Feature", variable=checkbox_var)
checkbox.pack()
# Create a menu bar
menu_bar = Menu(app)
app.config(menu=menu_bar)
# Create a File menu
file_menu = Menu(menu_bar, tearoff=0)
menu_bar.add_cascade(label="File", menu=file_menu)
file_menu.add_command(label="Open")
file_menu.add_command(label="Save")
file_menu.add_separator()
file_menu.add_command(label="Exit", command=app.quit)
# Create an Edit menu
edit_menu = Menu(menu_bar, tearoff=0)
menu_bar.add_cascade(label="Edit", menu=edit_menu)
edit_menu.add_command(label="Cut")
edit_menu.add_command(label="Copy")
edit_menu.add_command(label="Paste")
# Start the GUI event loop
app.mainloop()


