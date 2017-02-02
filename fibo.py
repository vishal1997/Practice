# -*- coding: utf-8 -*-
"""
Created on Wed Feb  1 01:45:59 2017

@author: Vishal
"""

def fibo(n,d):
    if n in d:
        return d[n]
    else:
        ans=fibo(n-1,d)+fibo(n-2,d)
        d[n]=ans
        return ans
        
d={1:1, 2:2}
print(fibo(5,d))