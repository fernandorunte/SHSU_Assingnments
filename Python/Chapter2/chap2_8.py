#tip,tax, total

total = 0.0
tippercent = 0.18
salestax = 0.07
taxowed = 0.0
tipowed = 0.0

charge = float(input('Enter the dinner charge: '))

taxowed= charge * salestax
tipowed = tippercent * charge
total = charge + taxowed + tipowed

print('Your charge was: ', charge)
print('Your tax owed is: ', taxowed)
print('Your tip owed is: ', tipowed)
print('Your total comes to: ', total)
