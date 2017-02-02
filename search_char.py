# -*- coding: utf-8 -*-
"""
Created on Fri Jan 20 17:31:40 2017

@author: Vishal
"""

def isIn(char, aStr):
    '''
    char: a single character
    aStr: an alphabetized string
    
    returns: True if char is in aStr; False otherwise
    '''
    # Your code here
    h=len(aStr)
    mid=h//2
    if aStr=='':
        return False
    if char == aStr[mid]:
        return True
    elif char > aStr[mid]:
        return isIn(char, aStr[mid+1 : ])
    elif char < aStr[mid]: 
        return isIn(char, aStr[ : mid-1])
    else:
        return False
        
value=isIn('h','abcdefgh')
print(value)