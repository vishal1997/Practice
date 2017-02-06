# -*- coding: utf-8 -*-
"""
Problem Statement: Enter a key as name and value as phone number
and for each query search if the contact is present 
Created on Mon Feb  6 18:50:09 2017

@author: Vishal
"""

def phoneBook():
    d={} # create a dictionary
    n=int(input()) # no. of contacts
    d = dict(input().split() for i in range(n)) # Name and phone number seperated by space
    i=0
    query=[] #create a list for storing the queries
    while 1: #ask user to enter the query till the user enters empty string
        try:
            reply = input() #if user enters a query
        except EOFError: # if user doesn't enter any query terminate the loop
            break
        query.append(reply) #add the query to the list of queries
        i+=1
    for j in range(0,i): # display the result of all the queries
        if query[j] not in d.keys():
            print("Not found") # if the query is not found
        else:
            print(query[j]+"="+d[query[j]]) # if the query is found
    
    
phoneBook()
