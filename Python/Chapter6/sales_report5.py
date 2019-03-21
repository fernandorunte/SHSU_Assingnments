# This program displays the total of the
# amounts in the sales_data.txt file.

def main():
    # Initialize an accumulator.
    total = 0.0
    
    try:
        # Open the sales_data.txt file.
        infile = open('sales_data.txt', 'r')

        # Read the values from the file and
        # accumulate them.
        for line in infile:
            amount = float(line)
            total += amount

        # Close the file.
        infile.close()
    except Exception as err:
        print(err)
    else:
        # Will be executed Only if no exception occurs.
        print(format(total, ',.2f'))
    finally:
        # Will be executed whether an exception occurs or not.
        print("Thank You for using the Program anyways Bye!")

# Call the main function.
main()
