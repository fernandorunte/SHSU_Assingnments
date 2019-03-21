#ingredient adjuster

amountwanted = float(input('Enter amount of cookies desired: '))


sugarneeded = 0.0
butterneeded = 0.0
flourneeded = 0.0

sugarneeded = (1.5 * amountwanted) / 48.0
butterneeded = (1 * amountwanted) / 48.0
flourneeded = (2.75 * amountwanted) / 48.0


print('You need this amount of sugar: ', sugarneeded)
print('You need this amount of butter: ', butterneeded)
print('You need this amount of flur: ', flourneeded)
