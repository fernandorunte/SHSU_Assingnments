#chap7_3 

rainfall = [0] * 12
total = 0.0;
avg = 0.0;

for x in range(12):
    userinput = int(input("Enter in rainfall: "))
    rainfall[x] = userinput
    total += userinput
avg = total / 12

maxrain = max(rainfall)
minrain = min(rainfall)

print("Total rainfall is: ", total)
print("Average rainfaill is: ", avg)
print("Max rainfall is: ", maxrain)
print("Min rainfall is: ", minrain)
print(rainfall)
