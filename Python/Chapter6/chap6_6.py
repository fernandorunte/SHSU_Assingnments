#chap 6_6

def main():
    # Open a file for reading.
    infile = open('numbers.txt', 'r')
    total = 0
    count = 0
    
    # Read three numbers from the file.

    
    for line in infile:
        num1 = int(line)
        total += num1
        count += 1
    
    average = total/count
    print('The average is:', average)

        
    # Close the file.
    infile.close()
    
   

  

# Call the main function.
main()
