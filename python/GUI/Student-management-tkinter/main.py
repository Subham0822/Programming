import customtkinter as ctk
from tkinter import messagebox
import json
import csv

# Save user data in a JSON file
USER_DATA_FILE = "users.json"

# Function to load user data
def load_user_data():
    try:
        with open(USER_DATA_FILE, "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return {}

# Function to save user data
def save_user_data(data):
    with open(USER_DATA_FILE, "w") as file:
        json.dump(data, file)

# Login function
def login():
    username = username_entry.get()
    password = password_entry.get()
    users = load_user_data()

    if username in users and users[username] == password:
        messagebox.showinfo("Login Successful", "Welcome!")
        open_dashboard()
    else:
        messagebox.showerror("Error", "Invalid username or password")

# Signup function
def signup():
    username = username_entry.get()
    password = password_entry.get()

    if not username or not password:
        messagebox.showerror("Error", "Fields cannot be empty!")
        return

    users = load_user_data()

    if username in users:
        messagebox.showerror("Error", "Username already exists")
    else:
        users[username] = password
        save_user_data(users)
        messagebox.showinfo("Signup Successful", "Account created successfully!")

# Open dashboard after login
def open_dashboard():
    login_window.destroy()

    dashboard = ctk.CTk()
    dashboard.title("Student Management System")
    dashboard.geometry("800x500")

    # Navbar
    nav_frame = ctk.CTkFrame(dashboard, corner_radius=10)
    nav_frame.pack(side="top", fill="x", padx=10, pady=10)

    home_btn = ctk.CTkButton(nav_frame, text="Home", command=lambda: show_page("Home"))
    home_btn.pack(side="left", padx=10, pady=10)

    courses_btn = ctk.CTkButton(nav_frame, text="Courses", command=lambda: show_page("Courses"))
    courses_btn.pack(side="left", padx=10, pady=10)

    contact_us_btn = ctk.CTkButton(nav_frame, text="Contact Us", command=lambda: show_page("Contact Us"))
    contact_us_btn.pack(side="left", padx=10, pady=10)

    # Content area
    content_frame = ctk.CTkFrame(dashboard)
    content_frame.pack(fill="both", expand=True, padx=10, pady=10)

    content_label = ctk.CTkLabel(content_frame, text="Welcome to the Dashboard", font=("Arial", 18))
    content_label.pack(pady=20)

    def show_page(page):
        for widget in content_frame.winfo_children():
            widget.destroy()

        if page == "Home":
            label = ctk.CTkLabel(content_frame, text="Welcome to the Dashboard", font=("Arial", 18))
            label.pack(pady=20)
        elif page == "Courses":
            show_courses(content_frame)
        elif page == "Contact Us":
            show_contact_us(content_frame)

    def show_courses(parent):
        courses = [
            {"name": "Mathematics", "duration": "3 months", "details": "Learn advanced mathematical techniques and applications."},
            {"name": "Physics", "duration": "4 months", "details": "Explore the laws of nature and understand the physical world."},
            {"name": "Chemistry", "duration": "3 months", "details": "Study chemical reactions, properties, and structures."},
            {"name": "Biology", "duration": "4 months", "details": "Dive into the science of life and living organisms."},
            {"name": "Computer Science", "duration": "6 months", "details": "Master programming, algorithms, and software development."}
        ]

        ctk.CTkLabel(parent, text="Available Courses", font=("Arial", 16, "bold")).pack(pady=10)

        for course in courses:
            course_frame = ctk.CTkFrame(parent)
            course_frame.pack(fill="x", padx=10, pady=5)

            ctk.CTkLabel(course_frame, text=course["name"], font=("Arial", 14, "bold"), anchor="w").pack(side="left", fill="x", expand=True, padx=10, pady=5)
            ctk.CTkLabel(course_frame, text=f"Duration: {course['duration']}", font=("Arial", 12)).pack(side="left", padx=10)

            view_details_btn = ctk.CTkButton(course_frame, text="View Details", command=lambda c=course: open_course_details(c))
            view_details_btn.pack(side="right", padx=10, pady=5)

    def open_course_details(course):
        details_window = ctk.CTkToplevel(dashboard)
        details_window.title(f"{course['name']} Details")
        details_window.geometry("400x300")

        ctk.CTkLabel(details_window, text=f"{course['name']} Details", font=("Arial", 18)).pack(pady=10)
        ctk.CTkLabel(details_window, text=f"Duration: {course['duration']}", font=("Arial", 12)).pack(pady=5)
        ctk.CTkLabel(details_window, text=course['details'], font=("Arial", 12), wraplength=350).pack(pady=5)

        def open_application_form():
            application_window = ctk.CTkToplevel(details_window)
            application_window.title("Application Form")
            application_window.geometry("400x380")

            ctk.CTkLabel(application_window, text="Name:", font=("Arial", 12)).pack(pady=2)
            name_entry = ctk.CTkEntry(application_window)
            name_entry.pack(pady=2)

            ctk.CTkLabel(application_window, text="Email:", font=("Arial", 12)).pack(pady=2)
            email_entry = ctk.CTkEntry(application_window)
            email_entry.pack(pady=2)

            ctk.CTkLabel(application_window, text="Phone:", font=("Arial", 12)).pack(pady=2)
            phone_entry = ctk.CTkEntry(application_window)
            phone_entry.pack(pady=2)

            ctk.CTkLabel(application_window, text="Qualification:", font=("Arial", 12)).pack(pady=2)
            qualification_entry = ctk.CTkEntry(application_window)
            qualification_entry.pack(pady=2)

            def submit_application():
                name = name_entry.get()
                email = email_entry.get()
                phone = phone_entry.get()
                qualification = qualification_entry.get()

                if not name or not email or not phone or not qualification:
                    messagebox.showerror("Error", "All fields are required!")
                    return

                with open("applications.csv", "a", newline="") as file:
                    writer = csv.writer(file)
                    writer.writerow([name, email, phone, qualification])

                messagebox.showinfo("Success", "Application submitted successfully!")
                application_window.destroy()

            ctk.CTkButton(application_window, text="Submit", command=submit_application).pack(pady=10)
            ctk.CTkButton(application_window, text="Close", command=application_window.destroy).pack(pady=10)

        ctk.CTkButton(details_window, text="Apply", command=open_application_form).pack(pady=10)
        ctk.CTkButton(details_window, text="Close", command=details_window.destroy).pack(pady=10)

    def show_contact_us(parent):
        # Clear the parent frame
        for widget in parent.winfo_children():
            widget.destroy()

        ctk.CTkLabel(parent, text="Contact Us", font=("Arial", 16, "bold")).pack(pady=10)

        # Input fields
        name_entry = ctk.CTkEntry(parent, placeholder_text="Name")
        name_entry.pack(pady=5)

        phone_entry = ctk.CTkEntry(parent, placeholder_text="Phone")
        phone_entry.pack(pady=5)

        address_entry = ctk.CTkEntry(parent, placeholder_text="Address")
        address_entry.pack(pady=5)

        comment_entry = ctk.CTkEntry(parent, placeholder_text="Comment")
        comment_entry.pack(pady=5)

        # Function to save contact details
        def submit_contact():
            name = name_entry.get()
            phone = phone_entry.get()
            address = address_entry.get()
            comment = comment_entry.get()

            if not name or not phone or not address or not comment:
                messagebox.showerror("Error", "All fields are required!")
                return

            # Save details to CSV file
            with open("contact_us.csv", "a", newline="") as file:
                writer = csv.writer(file)
                writer.writerow([name, phone, address, comment])

            messagebox.showinfo("Success", "Contact details submitted successfully!")

            # Clear the fields
            name_entry.delete(0, "end")
            phone_entry.delete(0, "end")
            address_entry.delete(0, "end")
            comment_entry.delete(0, "end")

        # Submit button
        ctk.CTkButton(parent, text="Submit", command=submit_contact).pack(pady=10)


    dashboard.mainloop()

# Login window
login_window = ctk.CTk()
login_window.title("Login")
login_window.geometry("400x300")

ctk.CTkLabel(login_window, text="Login", font=("Arial", 20, "bold")).pack(pady=10)
username_entry = ctk.CTkEntry(login_window, placeholder_text="Username")
username_entry.pack(pady=10)
password_entry = ctk.CTkEntry(login_window, placeholder_text="Password", show="*")
password_entry.pack(pady=10)

ctk.CTkButton(login_window, text="Login", command=login).pack(pady=10)
ctk.CTkButton(login_window, text="Signup", command=signup).pack(pady=10)

login_window.mainloop()
