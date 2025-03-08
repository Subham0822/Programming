def getElement(tup):
    if len(tup) < 4:
        return "The tuple does not have enough elements."
    
    return tup[-4]

tup = (2,5,7,1,4,8,0)
result = getElement(tup)
print("The 4th element from the tuple is:", result)
