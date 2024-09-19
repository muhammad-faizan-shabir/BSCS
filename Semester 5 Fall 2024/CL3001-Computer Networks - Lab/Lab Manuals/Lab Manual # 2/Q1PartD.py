def main():
    num = input("Enter the number: ")
    
    reverseNum = num[::-1]

    if(num == reverseNum):
        print("The number is palindrome!")
    else:
        print("The number is NOT palindrome!")

main()