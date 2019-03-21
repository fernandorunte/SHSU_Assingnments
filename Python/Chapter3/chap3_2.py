##areas of rectangles

length1=int(input('enter lenght of the first rectangle: '))
width1=int(input('enter the width of the first rectangle: '))
length2=int(input('enter lenght of the second rectangle: '))
width2=int(input('enter the width of the second rectangle: '))

area1= length1*width1
area2= length2*width2
           
if area1 > area2:
    print('the first rectangle is bigger')
else:
    if area1 < area2:
        print('the second rectanble is bigger')
    else:
        print('they are the same sise')
