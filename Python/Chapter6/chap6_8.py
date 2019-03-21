#chap 6_8
import random

def main():
    # Open a file for writing.
    infile = open('randomnumbers.txt', 'r')
    
    count = 0
    total = 0
 
   
    for line in infile:
        num = int(line)
        total += num
        count += 1
        

    # Close the file.
    infile.close()
    print("The total numbers in file is: ", count)
    print("The total of all numbers added is: ", total)
# Call the main function.
main()
