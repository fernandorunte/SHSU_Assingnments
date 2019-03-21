# This program writes three lines of data
# to a file.
def main():
    # Open a file named philosophers.txt.
    outfile = open('philosophers11.txt', 'a')

    # Write the names of three philosphers
    # to the file.
    outfile.write('John Locke Again\n')
    outfile.write('David Hume Again\n')
    outfile.write('Edmund Burke Again\n')

    # Close the file.
    outfile.close()

# Call the main function.
main()
