# Task 1
def checkDivisibilityByThree(lst):
    return [x for x in lst if x%3==0]

lst=[0,1,4,9,16,25,36,49,64,81] # sample list
newList= checkDivisibilityByThree(lst) # calling the function 
print("Elements divisible by 3 are:",newList) # printing the result of the function