# Task 2
def split_and_merge(a,b):
    lenA= len(a) # find length of a
    lenB= len(b) # find length of b
    
    if(lenA%2==0): # case when length of a is even
        aFront=a[0:lenA//2]
        aBack= a[lenA//2::]
    else: # case when length of a is odd
        aFront= a[0:(lenA//2)+1]
        aBack= a[(lenA//2)+1::]
    
    if(lenB%2==0): # case when length of b is even
        bFront=b[0:lenB//2]
        bBack= b[lenB//2::]
    else: # case when length of b is odd
        bFront= b[0:(lenB//2)+1]
        bBack= b[(lenB//2)+1::]
    
    return aFront+bFront+aBack+bBack # return the newly constructed string

a="abcde" # sample string a
b="fghij" # sample string b
print("Output of split_and_merge():",split_and_merge(a,b)) # calling the function and printing the result    