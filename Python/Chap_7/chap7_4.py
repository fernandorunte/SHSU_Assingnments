#chap7_4

numbers = [0] * 3
total = 0.0;
avg = 0.0;


for x in range(3):
    userinput = float(input("Enter number value: "))
    numbers[x] = userinput
    total += userinput

avg = total / 3
maxnum = max(numbers)
minnum = min(numbers)


print("Total is: ", total)
print("Average is: ", avg)
print("Max is: ", maxnum)
print("Min is: ", minnum)
print(numbers)
