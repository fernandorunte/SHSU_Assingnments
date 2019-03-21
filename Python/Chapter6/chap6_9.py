#chap 6_9

def main():
    # Open a file for reading.
    infile = open('numbers.txt', 'r')
    total = 0
    count = 0
    
    # Read three numbers from the file.

    try:
        for line in infile:
            num1 = int(line)
            total += num1
            count += 1
    except IOError:
        print("There was an error reading the file, please make sure file name exists!")
    except ValueError:
        print("The infile had improper numbers, program handles integer values only.")
    else:
        average = total/count
        print('The average is:', average)

        
    # Close the file.
    infile.close()
    
   

  

# Call the main function.
main()
