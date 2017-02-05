# -*- coding: utf-8 -*-
"""
Created on Sun Feb  5 17:49:59 2017

@author: Vishal
"""

def string_combined(s1,s2):
    s3=[] # list to store the desired output
    s1_a=list(s1) # convert the string to list
    s2_a=list(s2) # convert the string to list
    while s1_a and s2_a: #loop terminate when 1 of the two list becomes null 
        if s1_a[0]==s2_a[0]: #if both the cahr at list 1 and 2 are same
            s3.append(s1_a.pop(0)) #pop the char from both the list and append to s3
            s3.append(s2_a.pop(0))
        elif s1_a[0] < s2_a[0]: #Compare the 1st char of each list
            s3.append(s1_a.pop(0)) #if the char at list 1 is smaller than the char is poped out and append to s3
        else:
            s3.append(s2_a.pop(0)) #if the cahr at 2nd list is smaller than char is poped and apppend to s3  
    if s1_a: #if the while loop terminates because list 2 becomes null extend string 1 to s3
        s3.extend(s1_a)
    else: # if the while loop terminates because list 1 becomes null extend string 2 to s3
        s3.extend(s2_a)
    s3=''.join(s3) # join the list
    print(s3) # print the string
    return

s1=input("Enter the 1st string")
s2=input("Enter the 2nd string")
string_combined(s1,s2)
        