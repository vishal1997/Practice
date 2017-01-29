# -*- coding: utf-8 -*-
"""
Created on Sun Jan 22 23:46:12 2017

@author: Vishal
"""

# Paste your code into this box
balance = 3329
annualInterestRate = 0.2
monthlyInterestRate=annualInterestRate/12.0
updateBalance=balance
unpaidBalance=''
paid=10
i=0
while i<12 and updateBalance!=0:
    unpaidBalance=updateBalance-paid
    updateBalance=(unpaidBalance)+(monthlyInterestRate*unpaidBalance)
    
    i+=1
rem=int((paid*100))+.5
print('Remaining balance: '+str(rem/100))
    
    