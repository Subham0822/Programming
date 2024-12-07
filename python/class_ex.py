class dog:
    def __init__(self, name, breed):
        self.name = name
        self.breed = breed

    def update(self):
        self.name = "Buzo"
        self.breed = "German Shephard"

    def compare(self, other):
        if self.name == other.name:
            return True

        else:
            return False


dog1 = dog("Tommy", "Pug")
dog2 = dog("Tommy", "Pug")

print("Original: ",dog1.name)
print("Original: ",dog1.breed)
if dog1.compare(dog2):
    print("Same")
else:
    print("Diff")
dog1.update()
print("Updated (dog1): ",dog1.name)
print("Updated (dog1): ",dog1.breed)
if dog1.compare(dog2):
    print("Same")
else:
    print("Diff")
