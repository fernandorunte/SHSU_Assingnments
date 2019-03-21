##age classifier

age = int(input('enter your age'))

if age >= 20:
    print('you are an adult')
else:
    if age >= 13:
         print('you are a teenager')
    else:
        if age > 1:
            print('you are an child')
        else:
            print('you are an infant')
