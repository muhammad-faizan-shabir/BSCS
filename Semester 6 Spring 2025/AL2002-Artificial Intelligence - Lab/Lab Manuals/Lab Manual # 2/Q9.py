#Task 9
try:
    x = float(input("Enter x: ")) # get float input 1
    y = float(input("Enter y: ")) # get float input 2
    
    addition=x+y # perform addition
    multiplication=x*y # perform multiplication
    division=x/y # perform division
    
    print("Addition:",addition,"Multiplication:",multiplication,"Division:",division) # print results
except ZeroDivisionError:
    print("Error! Division done by zero ",ZeroDivisionError)
except ValueError:
    print("Invalid value entered ",ValueError)