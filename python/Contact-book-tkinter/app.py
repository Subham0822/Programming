import tkinter as tk
from tkmacosx import Button
from tkinter import ttk, messagebox
import json
from tkinter import PhotoImage
import re

# File to store contacts persistently
CONTACTS_FILE = "contacts.json"

# Function to load contacts from a file and ensure each contact has an 'id'
def load_contacts():
    try:
        with open(CONTACTS_FILE, "r") as file:
            loaded_contacts = json.load(file)
            # Ensure all contacts have an 'id' field, if missing assign a unique ID
            for index, contact in enumerate(loaded_contacts):
                if "id" not in contact:
                    contact["id"] = index + 1  # Assign a unique ID if missing
            return loaded_contacts
    except (FileNotFoundError, json.JSONDecodeError):
        return []

# Function to save contacts to a file
def save_contacts():
    with open(CONTACTS_FILE, "w") as file:
        json.dump(contacts, file, indent=4)

# Refresh the contact list display
def refresh_contact_list(filtered_contacts=None):
    for widget in contact_frame.winfo_children():
        widget.destroy()

    display_contacts = filtered_contacts if filtered_contacts else contacts

    if display_contacts:
        update_button.pack(side="right", padx=10, pady=5)
        delete_button.pack(side="right", padx=10, pady=5)
        
        global table
        table = ttk.Treeview(contact_frame, columns=("ID", "Name", "Phone", "Email", "Address"), show="headings")
        table.heading("ID", text="ID")
        table.heading("Name", text="Name")
        table.heading("Phone", text="Phone Number")
        table.heading("Email", text="Email")
        table.heading("Address", text="Address")
        table.column("ID", width=50, anchor="center")
        table.column("Name", width=120, anchor="center")
        table.column("Phone", width=120, anchor="center")
        table.column("Email", width=150, anchor="center")
        table.column("Address", width=200, anchor="center")

        for contact in display_contacts:
            table.insert("", "end", values=(contact["id"], contact["name"], contact["phone"], contact["email"], contact["address"]))
        table.pack(fill="both", expand=True)
    else:
        update_button.pack_forget()
        delete_button.pack_forget()
        no_contacts_label = tk.Label(contact_frame, text="No contacts to show", font=("Helvetica", 14),
                                     bg="#f7f9fc", fg="#6c757d")
        no_contacts_label.pack(pady=20)

# Add a new contact
def add_contact():
    global next_contact_id

    def save_contact():
        global next_contact_id
        name = name_entry.get()
        phone = phone_entry.get()
        email = email_entry.get()
        address = address_entry.get()

        if not (name):
            messagebox.showwarning("Warning", "Name is required!")
            return
        elif not (phone):
            messagebox.showwarning("Warning", "Phone Number is required!")
            return
        elif not (email):
            messagebox.showwarning("Warning", "Email is required!")
            return
        if (phone):
            if validate_mobile_number(phone):
                pass
            else:
                messagebox.showwarning("Warning", "Phone number is invalid")
                return
        if (email):
            if validate_email(email):
                pass
            else:
                messagebox.showwarning("Warning", "Email id invalid")
                return

        contacts.append({"id": next_contact_id, "name": name, "phone": phone, "email": email, "address": address})
        next_contact_id += 1
        save_contacts()
        messagebox.showinfo("Success", "Contact added successfully!")
        add_window.destroy()
        refresh_contact_list()

    def cancel():
        add_window.destroy()

    add_window = tk.Toplevel(root)
    add_window.title("Add Contact")
    add_window.geometry("450x400")
    add_window.configure(bg="#f4f6f9")

    def create_input_field(label_text, placeholder):
        tk.Label(add_window, text=label_text, font=("ComicSansMS", 12), bg="#f4f6f9", fg="#333333").pack(pady=5, anchor="w", padx=20)
        entry = tk.Entry(add_window, font=("ComicSansMS", 12), bg="#000000", fg="#ffffff", relief="flat", bd=2)
        entry.insert(0, placeholder)
        entry.pack(padx=20, pady=5, fill="x")
        return entry

    tk.Label(add_window, text="Add New Contact", font=("ComicSansMS", 16, "bold"), bg="#f4f6f9", fg="#333333").pack(pady=10)

    name_entry = create_input_field("Name:", "")
    phone_entry = create_input_field("Phone Number:", "")
    email_entry = create_input_field("Email:", "")
    address_entry = create_input_field("Address:", "")

    button_frame = tk.Frame(add_window, bg="#f4f6f9")
    button_frame.pack(pady=20)

    make_button(button_frame, "Save", save_contact, "#28a745", "#ffffff", "#218838", "#ffffff").pack(side="left", padx=10)
    make_button(button_frame, "Cancel", cancel, "#dc3545", "#ffffff", "#c82333", "#ffffff").pack(side="left", padx=10)

# Delete a selected contact
def delete_contact():
    selected_item = table.selection()
    if not selected_item:
        messagebox.showwarning("Warning", "No contact selected to delete!")
        return
    
    selected_id = int(table.item(selected_item, "values")[0])
    global contacts
    contacts = [contact for contact in contacts if contact["id"] != selected_id]

    save_contacts()
    messagebox.showinfo("Success", "Contact deleted successfully!")
    refresh_contact_list()

# Form to update a contact
def update_contact():
    selected_item = table.selection()
    if not selected_item:
        messagebox.showwarning("Warning", "No contact selected to update!")
        return

    selected_id = int(table.item(selected_item, "values")[0])
    # Fetch the selected contact's details
    selected_contact = next((contact for contact in contacts if contact["id"] == selected_id), None)
    if not selected_contact:
        messagebox.showerror("Error", "Contact not found!")
        return

    def save_updated_contact():
        name = name_entry.get()
        phone = phone_entry.get()
        email = email_entry.get()
        address = address_entry.get()

        if not (name):
            messagebox.showwarning("Warning", "Name is required!")
            return
        elif not (phone):
            messagebox.showwarning("Warning", "Phone Number is required!")
            return
        elif not (email):
            messagebox.showwarning("Warning", "Email is required!")
            return
        if (phone):
            if validate_mobile_number(phone):
                pass
            else:
                messagebox.showwarning("Warning", "Phone number is invalid")
                return
        if (email):
            if validate_email(email):
                pass
            else:
                messagebox.showwarning("Warning", "Email id invalid")
                return

        for contact in contacts:
            if contact["id"] == selected_id:
                contact.update({"name": name, "phone": phone, "email": email, "address": address})
                break

        save_contacts()
        messagebox.showinfo("Success", "Contact updated successfully!")
        update_window.destroy()
        refresh_contact_list()

    def cancel_update():
        update_window.destroy()

    update_window = tk.Toplevel(root)
    update_window.title("Update Contact")
    update_window.geometry("450x400")
    update_window.configure(bg="#f4f6f9")

    tk.Label(update_window, text="Update Contact", font=("ComicSansMS", 16, "bold"), bg="#f4f6f9", fg="#333333").pack(pady=10)

    def create_input_field(label_text, placeholder):
        tk.Label(update_window, text=label_text, font=("ComicSansMS", 12), bg="#f4f6f9", fg="#333333").pack(pady=5, anchor="w", padx=20)
        entry = tk.Entry(update_window, font=("ComicSansMS", 12), bg="#000000", fg="#ffffff", relief="flat", bd=2)
        entry.insert(0, placeholder)
        entry.pack(padx=20, pady=5, fill="x")
        return entry

    name_entry = create_input_field("Name:", selected_contact["name"])
    phone_entry = create_input_field("Phone Number:", selected_contact["phone"])
    email_entry = create_input_field("Email:", selected_contact["email"])
    address_entry = create_input_field("Address:", selected_contact["address"])

    button_frame = tk.Frame(update_window, bg="#f4f6f9")
    button_frame.pack(pady=20)

    make_button(button_frame, "Save", save_updated_contact, "#28a745", "#ffffff", "#218838", "#ffffff").pack(side="left", padx=10)
    make_button(button_frame, "Cancel", cancel_update, "#dc3545", "#ffffff", "#c82333", "#ffffff").pack(side="left", padx=10)

#Function to search across the db
def search_contact():
    search_term = search_var.get().strip().lower()
    if not search_term:
        pass

    # Filter contacts based on the search term
    filtered_contacts = [
        contact for contact in contacts
        if search_term in str(contact["name"]).lower()
        or search_term in str(contact["phone"]).lower()
        or search_term in str(contact["email"]).lower()
        or search_term in str(contact["address"]).lower()
    ]

    if not filtered_contacts:
        messagebox.showwarning("Warning", "No such contact found!")
        return

    # Display filtered contacts in the table
    for widget in contact_frame.winfo_children():
        widget.destroy()

    global table
    table = ttk.Treeview(contact_frame, columns=("ID", "Name", "Phone", "Email", "Address"), show="headings")
    table.heading("ID", text="ID")
    table.heading("Name", text="Name")
    table.heading("Phone", text="Phone Number")
    table.heading("Email", text="Email")
    table.heading("Address", text="Address")
    table.column("ID", width=50, anchor="center")
    table.column("Name", width=120, anchor="center")
    table.column("Phone", width=120, anchor="center")
    table.column("Email", width=150, anchor="center")
    table.column("Address", width=200, anchor="center")

    for contact in filtered_contacts:
        table.insert("", "end", values=(contact["id"], contact["name"], contact["phone"], contact["email"], contact["address"]))
    table.pack(fill="both", expand=True)

#Function to validate email
def validate_email(email):
    email_pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    if re.match(email_pattern, email):
        return True
    return False

# Function to validate mobile number
def validate_mobile_number(number):
    # Define the regex pattern for a valid mobile number
    mobile_pattern = r'^[6-9]\d{9}$'  # Starts with 6-9 and has 10 digits
    if re.match(mobile_pattern, number):
        return True
    return False


# Function to create a styled button
def make_button(parent, text, cmd, bg, fg, hover_bg, hover_fg):
    return Button(
        parent,
        text=text,
        command=cmd,
        bg=bg,
        fg=fg,
        activebackground=hover_bg,
        activeforeground=hover_fg,
        font='ComicSansMS 12 bold',
        borderless=1,
        padx=8,
        pady=6
    )

# Initialize the main application window
root = tk.Tk()
root.title("Contact Book")
root.geometry("888x444")
# root.iconphoto(True, PhotoImage(file='./assets/contact-icon.png'))
root.configure(bg="#f7f9fc")

# Top bar with buttons
top_bar = tk.Frame(root, bg="#343a40", height=40)
top_bar.pack(fill="x")

# Add a text field and search button in the top bar
search_var = tk.StringVar()  # Variable to hold search input
search_entry = tk.Entry(top_bar, textvariable=search_var, font="ComicSansMS 12", width=20)
search_entry.pack(side="left", padx=5, pady=5)

search_button = make_button(
    top_bar, "Search", search_contact,
    bg="#17a2b8", fg="#ffffff",
    hover_bg="#138496", hover_fg="#ffffff"
)
search_button.pack(side="left", padx=10, pady=5)

# Load existing contacts
contacts = load_contacts()
next_contact_id = max([contact["id"] for contact in contacts], default=0) + 1

add_button = make_button(
    top_bar, "Add Contact", add_contact,
    bg="#007bff", fg="#ffffff",
    hover_bg="#0056b3", hover_fg="#ffffff"
)
add_button.pack(side="right", padx=10, pady=5)

update_button = make_button(
    top_bar, "Update Contact", update_contact,
    bg="#ffc107", fg="#ffffff",
    hover_bg="#e0a800", hover_fg="#ffffff"
)

delete_button = make_button(
    top_bar, "Delete Contact", delete_contact,
    bg="#dc3545", fg="#ffffff",
    hover_bg="#c82333", hover_fg="#ffffff"
)

# Frame to display contacts
contact_frame = tk.Frame(root, bg="#f7f9fc")
contact_frame.pack(fill="both", expand=True, padx=0, pady=0)

# Refresh the contact list
refresh_contact_list()

# Run the application
root.mainloop()
