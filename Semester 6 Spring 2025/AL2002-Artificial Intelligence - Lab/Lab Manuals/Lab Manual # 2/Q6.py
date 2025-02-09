# Task 6
def getFrequencyCount(lst):
    d={} # dictionary to hold frequencies
    
    for num in lst:
        d[num]= d.get(num,0)+1 # count frequency of each element in the list
    
    return d

lst=[1,2,2,3,4,2] # sample list
print("Dictionary with Frequency Count is:",getFrequencyCount(lst)) # calling the function and printing the result