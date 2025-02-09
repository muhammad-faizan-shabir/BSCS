# Task 5
def binarySearch(lst,target):
    size=len(lst)
    start=0
    end=size-1
    
    while(start <= end): # loop runs until start becomes greater than end
        mid = (start + end)//2
        if(lst[mid]==target):
            return mid # return index if target is found
        elif(lst[mid]>target):
            end=mid-1
        else:
            start=mid+1
    
    return -1 # if loop ends, return -1 since target not found

lst=[1,2,3,4,5,6,7] # sample sorted list
target= int(input("Enter target value:"))  # input target
print("Target",target,"found at index:",binarySearch(lst,target)) # calling the function and printing the result