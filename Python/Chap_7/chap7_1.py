#chap7_1



storesale = [0] * 7
total = 0

for x in range(7):
    storesale[x] = int(input("Enter store sales: "))
    
for x in storesale:
    total += storesale[x]
    
print("The total is: ", total)
    
