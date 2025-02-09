# Task 7
def getFrequentKeys(d1):
    d2={} # dictionary to store value frequency count
    for key in d1:
        d2[d1[key]]= d2.get(d1[key],0) + 1 # count frequency of each value in the original dictionary
    
    maxFreq = -1 
    for freq in d2.values(): # finding maximum frequency
        if(freq>maxFreq):
            maxFreq=freq
    
    val_max_freq = [] # all values with max frequency
    for item in d2.items(): # finding all values with maximum frequency
        if(item[1]==maxFreq):
            val_max_freq.append(item[0])
    
    keys=[] 
    for key in d1:
        if(d1[key] in val_max_freq): # check if key has value with max frequency
            keys.append(key)
    
    return keys

d1={'a':1,'b':2,'c':2,'d':3} # sample dictionary
print("Most frequent keys:",getFrequentKeys(d1)) # calling the function and printing the result    