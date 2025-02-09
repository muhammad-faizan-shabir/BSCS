# Task 4
def modifyTuple(tpl):
    lst=[]
    for i in range(0,len(tpl)-1): # loop stops at second last index
        lst.append(tpl[i]*tpl[i+1])
    
    return tuple(lst)
    
tpl=(1,5,7,8,10) # sample tuple
print("The modified tuple is: ",modifyTuple(tpl)) # calling the function and printing the result