#toal purchase

taxrate = 0.07
subtotal = 0.0
salestax = 0.0
total = 0.0
item1 = float(input('Enter price of item 1: '))
item2 = float(input('Enter price of item 2: '))
item3 = float(input('Enter price of item 3: '))
item4 = float(input('Enter price of item 4: '))
item5 = float(input('Enter price of item 5: '))

subtotal = (item1 + item2 +item3 +item4 +item5)
salestax = subtotal * taxrate
total = subtotal + salestax

print('The subtotal is: ', subtotal)
print('The amount of sales taxt is: ', salestax)
print('The toal price is: ', total)
