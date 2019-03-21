#male and female percentages

nummales = int(input('Enter the amount of males: '))
numfemales = int(input('Enter the amount of females: '))

totalclass = nummales + numfemales
percentmale = (nummales * 100) / totalclass
percentfemale = (numfemales* 100) / totalclass

print('Your class has a male percentage of: ', percentmale)
print('Your class has a female percentage of: ', percentfemale)
