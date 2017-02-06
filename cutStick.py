# -*- coding: utf-8 -*-
"""
Problem Statement:You are given n sticks, where the length of each stick is a 
positive integer. A cut operation is performed on the sticks such that all of 
them are reduced by the length of the smallest stick.

Created on Tue Feb  7 00:03:33 2017

@author: Vishal
"""


n = int(input().strip()) #input the number of array, strip removes the space from left and right
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')] # input array element in 1 line

def remove_list(arr): #update the array by removing 0
    i=0
    try: # to handle the index error, if all the elements are removed
        while arr[i]==0:
            arr.remove(0) # removes the 1st occurence of 0
    except IndexError:
        return #return if array is empty

def cut(): #function to count the number od sticks that are cut after each step
    if(len(arr)==0):
        return
    arr.sort() # sort the array
    min_value=arr[0] #store min value of the array
    length=len(arr) #store length of the array
    print(length) #number of stciks required to cut
    for i in range(0,length):
        arr[i]-=min_value # reduce the length of stick by the minimum value of the stick
    remove_list(arr) # remove the sticks with size 0
    cut()
    
    
cut()