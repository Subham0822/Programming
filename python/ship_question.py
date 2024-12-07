T = int(input("Enter the time(T) for the party: "))
E = []
L = []
for i in range(0,T):
    e = int(input(f"Enter the no. of guests entered in {i+1} hour: "))
    E.append(e)
for i in range(0,T):
    l = int(input(f"Enter the no. of guests leaving in {i+1} hour: "))
    L.append(l)
total = 0
max = 0
for i in range(0,T):
    print(f"Hour {i+1}:")
    print(f"Entry: {len(E)} Exit: {len(L)}")
    total = total + (E[i]-L[i])
    print(f"No. of guests in the ship: {total}")
    if max<=total:
        max = total
print(f"The maximum no. of guests present in the ship: {max}")



    
