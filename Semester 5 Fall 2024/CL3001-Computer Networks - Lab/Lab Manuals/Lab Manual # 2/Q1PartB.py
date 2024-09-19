def main():
    num1 = int(input("Enter the first number: "))
    num2 = int(input("Enter the second number: "))
    operator = input("Choose an operation (+, -, *, /): ")

    if (operator not in ['+','-','*','/']):
        print ("Invalid operator!")
    elif (operator == '+'):
        print ("Result: ", num1 + num2)
    elif (operator== '-'):
        print ("Result: ", num1-num2)
    elif (operator== '*'):
        print ("Result: ", num1*num2)
    else:
        if(num2==0):
            print ("Error! The denominator cannot be 0.")
        else:
            print ("Result: ",num1/num2)

main()