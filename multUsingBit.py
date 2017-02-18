# -*- coding: utf-8 -*-
"""
Problem : To multiply two numbers using Bit Manipulation
Created on Tue Feb 14 00:42:13 2017

@author: Vishal
"""

def mul(a,b):
    x=a     #assign a to x
    y=b     #assign b to y
    z=0     #assign 0 to z
    while x>0:  #continue till x is +ve
        if x%2==1:  #if x is odd then add y to z
            z=z+y
        y=y<<1      #if x is even then left shift y by 1 
        x=x>>1      #right shift x by 1 
    return z        #z is the value of x*y
print(mul(20,7))