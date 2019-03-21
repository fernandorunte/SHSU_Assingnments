#chap 6_5

def main():
    # Open a file for reading.
    infile = open('numbers.txt', 'r')
    total = 0
    
    # Read three numbers from the file.
    for line in infile:
        num1 = int(line)
        total += num1

    # Close the file.
    infile.close()

   

    # Display the numbers and their total.
    print('The total is:', total)

# Call the main function.
main()
