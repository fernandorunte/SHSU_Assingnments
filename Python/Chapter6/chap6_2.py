#assingment 6 part 2

name = list(input("Enter the name of a file: "))
count = len(name)
if (count < 5):
   for x in range(count):
       print(name[x], end='')
    
else:
    for x in range(5):
        print(name[x],end='')
