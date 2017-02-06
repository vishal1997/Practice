# -*- coding: utf-8 -*-
"""
Problem Statement : 
    Bob is a Research Assistant in the CSE Dept. of NIT Trichy. He is extremely intrigued 
    by arrays. He came across the following problem.
    Bob was given an array of size N. Jenny who is also a Computer Science student asked 
    Bob to answer K queries on the array. Each query is denoted by a pair of indices (X,Y).
    (The array holds 1-based indexing) Bob needs to find how many such numbers are there 
    in a X , a X+1 , a X+2 ,….,a Y-1 ,a Y such that the number of occurrences of the 
    number is equal to the number itself.

Created on Mon Feb  6 08:51:57 2017

@author: Vishal
"""

def queries():
    n,k=input("Enter the length of array and number of queries").split()
    n=int(n) #length of the array
    k=int(k) #number of query
    a=[] # array
    count=[] #count array
    print("Enter the array elements seperated by space")
    a=[int(x) for x in input().split()] #inpur array elements
    print("Enter the queries x y") #prompt usre to enter the number of query
    result=[0]*(k+1) #initialize the result array to zero
    for i in range(1, k+1):
        j,z=input().split() # enter the queries
        j=int(j) #typecast j to int
        z=int(z) #type cast z tto int
        count=[0]*(int(max(a))+1) # intialize the counter to 0 with size as max element of array
        l=int(j) 
        while l <= z:
            count[int(a[l-1])]+=1 #increment the element at index . idex is the element of array
            l+=1 
        while j <= z:
            if count[a[j-1]]==a[j-1]: # compare if the count is equal to the array element
                result[i]=count[a[j-1]] #if equla store it in result
            j+=1
    for i in range(1,k+1):
        print(result[i]) #display the result
                
queries();