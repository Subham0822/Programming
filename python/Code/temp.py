temp = float(input("Enter a temperature in degree Celcius: "))
if temp<0:
    print("Freezing weather.")

elif 0<=temp<10:
    print("Very Cold weather.")

elif 10<=temp<20:
    print("Cold weather.")

elif 20<=temp<30:
    print("Room temperature.")

elif 30<=temp<40:
    print("Hot")

else:
    print("Very Hot")
    
