sec=int(input("Enter seconds: "))
hours=sec//3600
remaining_seconds=sec%3600
minutes=remaining_seconds//60
seconds=remaining_seconds%60
print(f"Hours: {hours}")
print(f"Minutes: {minutes}")
print(f"Seconds: {seconds}")
