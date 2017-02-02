# -*- coding: utf-8 -*-
"""
Created on Fri Jan 20 10:02:16 2017

@author: Vishal
"""

low=0
high=100
x=''
ans=''
print('Please think of a number between 0 and 100!')
while x!='c':
    ans=int(((low+high)/2))
    print('Is your secret number '+str(ans)+'?')
    x=input('Enter '+"'h'" +'to indicate the guess is too high. Enter '+"'l'"+' to indicate the guess is too low. Enter '+"'c'" +'to indicate I guessed correctly.')
    if x=='h':
        high=ans
    elif x=='l':
        low=ans
    if x!='h' or x!='l' or x!='c':
        print('Sorry, I did not understand your input.')
print('Game over. Your secret number was:'+str(ans))