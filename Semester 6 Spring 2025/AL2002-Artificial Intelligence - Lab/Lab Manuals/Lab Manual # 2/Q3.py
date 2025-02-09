# Task 3
def sortTuples(lst):
    return sorted(lst,key =lambda x: x[-1]) # use the sorted function and pass the key as last element of the tuples

lst=[(1,7),(1,3),(3,4,5),(2,2)] # sample list of tuples
print("List of Tuples after sorting:",sortTuples(lst)) # calling the function and printing the result