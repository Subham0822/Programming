# Contact Book Application
A simple and user-friendly Contact Book Application built with Python's Tkinter GUI library, allowing users to efficiently manage their contacts. The app supports adding, updating, deleting, searching, and persisting contacts with a clean and modern interface.

## Features
- *Add Contacts*: Add new contacts with details such as Name, Phone Number, Email, and Address.
- *Update Contacts*: Modify the details of existing contacts.
- *Delete Contacts*: Remove a contact from the list permanently.
- *Search Contacts*: Quickly find contacts by name, phone number, email, or address.
- *Persist Data*: Contacts are saved to a JSON file to ensure data is not lost when the app is closed.

## Project Structure
```bash
Contact Book
├── contacts.json                # Persistent storage for contact data
├── assets/contact-icon.png      # Icon for the application window
├── app.py                       # Main script containing the application code
├── screenshots                  # Screenshots of the app
└── README.md                    # Documentation
```

## Setup Instructions
### Prerequisites
- Python 3.6 or higher installed.
- The tkinter library (comes pre-installed with Python).
- tkmacosx library for enhanced button styles (for macOS).

### Install Dependencies
If you don't have tkmacosx installed, run:
```bash
pip install tkmacosx
```

### Running the Application
1. Clone the repository or download the project files.
2. Navigate to the project folder.
3. Run the main Python script:
```bash
python app.py
```
4. The application window will open, allowing you to manage your contacts.

## File Details
```contacts.json```
- This file stores all the contact data in JSON format.
- It is automatically created and updated by the application.
  
```./assets/contact-icon.png```
- This is the icon used for the application window.

## Functional Overview
### Add Contact
- Click the "Add Contact" button.
- Fill in the details (Name, Phone, Email, Address).
- Save the contact.
### Update Contact
- Select a contact from the list.
- Click the "Update Contact" button.
- Modify the fields and save.
### Delete Contact
- Select a contact from the list.
- Click the "Delete Contact" button to remove it.
### Search Contact
- Use the search bar at the top to find contacts by name, phone, email, or address.

## Validation Rules
- *Name*: Cannot be empty.
- *Phone Number*: Must start with 6-9 and contain exactly 10 digits.
- *Email*: Must follow standard email format (e.g., example@domain.com).

## Screenshots
- *Main Window*: Shows the contact list with options to Add, Update, Delete, and Search. [Click here](./screenshots/Main%20Window.png)
- *Add Contact Form*: A clean and straightforward form to add new contacts. [Click here](./screenshots/Add%20Contact%20Form.png)
- *Update Contact Form*: Pre-filled fields for editing contact details. [Click here](./screenshots/Update%20Contact%20Form.png)

## Future Enhancements
- Export contacts to CSV or Excel.
- Import contacts from external files.
- Add categories or tags for organizing contacts.
- Enhanced UI/UX with theme options.

