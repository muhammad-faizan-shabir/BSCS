# Task 8
def getDictionaries(lst,key,value):
    newList=[]
    
    for d in lst:
        if(key in d and d[key]==value): # check if key-value pair exist in the dictionary
            newList.append(d)
    
    return newList

list_of_dicts=[
    {'name':'Alice','age':25},
    {'name': 'Bob','age':30},
    {'name': 'Charlie','age':25},
    {'name':'David','age':40}
] # sample list of dictionaries

key='age' # sample key
value=25 # sample value
print("Dictionaries with specified key-value pair:",getDictionaries(list_of_dicts,key,value)) # # calling the function and printing the result    