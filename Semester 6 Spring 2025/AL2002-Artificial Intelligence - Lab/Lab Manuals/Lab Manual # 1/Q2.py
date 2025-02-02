# Task 2
vehicle= input("Enter vehicle type: ")
hours= int(input("Enter parking hours: "))
vehicle=vehicle.lower()

rate=0
if(vehicle=="car"):
    rate=5
elif(vehicle=="motorcycle"):
    rate=2
elif(vehicle=="truck"):
    rate=10
else:
    print("Error! Wrong vehicle type.")

if(hours>10):
    fee= 0.8 * hours * rate
    print("Total Parking Fee(20% Discount Applied): ",fee)
else:
    fee= hours * rate
    print("Total Parking Fee: ",fee)
    