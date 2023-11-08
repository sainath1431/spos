import tkinter as tk
# Create a function to handle button click event
def on_button_click():
    label.config(text="Hello, Python GUI!")
# Create the main application window
app = tk.Tk()
app.title("Python GUI Example")
# Create a label widget
label = tk.Label(app, text="Welcome to Python GUI")
label.pack(pady=10)
# Create a button widget
button = tk.Button(app, text="Click me", command=on_button_click)
button.pack()
# Start the GUI event loop
app.mainloop()
