#sales tax


statetax = 0.05
countytax = 0.025
statetotal = 0.0
countytotal = 0.0
totalsalestax = 0.0
totalsale = 0.0

purchase_amount = float(input('Enter purchase amount'))
statetotal = purchase_amount * statetax
countytotal = purchase_amount * countytax
totalsalestax = statetotal + countytotal
totalsale = totalsalestax + purchase_amount

print('The purchase amount enterted is: ',purchase_amount)
print('The state sales tax is: ', statetotal)
print('The county sales taxt is: ', countytotal)
print('The total sales taxt is: ', totalsalestax)
print('The total sale price is: ', totalsale)
