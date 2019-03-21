## mass and weight

mass=float(input('enter mass of object: ' ))
weight=mass*9.8

print('the weight is: ', weight)
if weight > 500:
    print('the object is too heavy')
else:
    if weight < 100:
        print('the object is too light')
