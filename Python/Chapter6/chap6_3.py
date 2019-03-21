#assingment 6 part 3

name = input("Enter the name of a file: ")


filein = open(name,'r')
feed = filein.readline()
counter = 0

while (feed != ''): 
   feed = filein.readline()
   counter += 1
   print(counter,": ",feed)

filein.close()
