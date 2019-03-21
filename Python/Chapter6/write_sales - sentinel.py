# This program prompts the user for sales amounts
# and writes those amounts to the sales.txt file.

def main():    

    # Open a new file named sales.txt.
    sales_file = open('sales.txt', 'w')

    # Get the amount of sales for each day and write
    # it to the file.
    sales=0
    count=1
    while sales!=-1:
        # Get the sales for a day.
        sales = float(input('Enter the sales for day #' + \
                            str(count) + ': '))
        # Write the sales amount to the file.
        if sales!=-1:
            sales_file.write(str(sales) + '\n')
            count+=1
    # Close the file.
    sales_file.close()
    print('Data written to sales.txt.')

# Call the main function.
main()
