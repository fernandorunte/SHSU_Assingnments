#chap 6_4

def main():

    infile = open('names.txt', 'r')

    count = 0
    contents = infile.readline()

    while (contents != ''):
       count += 1
       contents = infile.readline()
    print("The total count of names was: ", count)

    



main()
