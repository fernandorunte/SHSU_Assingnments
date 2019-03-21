#chap 6_7
import random

def main():
    # Open a file for writing.
    outfile = open('randomnumbers.txt', 'w')
    count = int(input("Enter how many numbers to be generated: "))
    
    
 
   
    for x in range(count):
        num = random.randint(1,500)
        outfile.write(str(num) + '\n')
        

    # Close the file.
    outfile.close()
    print("Data printed to file")
    
# Call the main function.
main()
