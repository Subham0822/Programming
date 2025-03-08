class Library:
    num_books = 0
    num_users = 0
    total_price = 0.0

    def __init__(self, book_name=None, book_price=None, user_name=None):
        if book_name and book_price:
            self.book_name = book_name
            self.book_price = book_price
            Library.num_books += 1
            Library.total_price += book_price
        elif user_name:
            self.user_name = user_name
            Library.num_users += 1

    def display_book_details(self):
        if hasattr(self, 'book_name'):
            print(f"Book Name: {self.book_name}, Price: {self.book_price}")

    def display_user_details(self):
        if hasattr(self, 'user_name'):
            print(f"User Name: {self.user_name}")

# Taking input from the user
books = []
users = []

num_books = int(input("Enter the number of books: "))
for _ in range(num_books):
    name = input("Enter book name: ")
    price = float(input("Enter book price: "))
    books.append(Library(book_name=name, book_price=price))

num_users = int(input("Enter the number of users: "))
for _ in range(num_users):
    name = input("Enter user name: ")
    users.append(Library(user_name=name))

# Display book and user details
for book in books:
    book.display_book_details()

for user in users:
    user.display_user_details()

# Display totals
print(f"Total number of books: {Library.num_books}")
print(f"Total number of users: {Library.num_users}")
print(f"Total price of books: {Library.total_price}")
