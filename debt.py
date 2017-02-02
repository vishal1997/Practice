# -*- coding: utf-8 -*-
"""
Created on Sun Jan 22 11:58:40 2017

@author: Vishal
"""


balance = 484
annualInterestRate = 0.2
monthlyPaymentRate = 0.04
monthlyInterestRate=.18/12.0
updateBalance=balance
unpaidBalance=''
paid=''
for i in range(12):
    paid=updateBalance*monthlyPaymentRate
    unpaidBalance=updateBalance-paid
    updateBalance=(unpaidBalance)+(monthlyInterestRate*unpaidBalance)
    rem=int((updateBalance*100)+.5)
    print(str(i+1)+'='+str(rem/100))

    
    