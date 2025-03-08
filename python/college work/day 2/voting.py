age=int(input("Enter your age: "))

if age>=18:
    print("Eligible for voting")
else:
    print(f"{18-age} years left for eligibility")
