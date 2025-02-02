# Task 5
def check_palindrome():
    string = input("Enter a string: ")
    string = string.lower()
    
    if(string == string[::-1]):
        print("The string is a palindrome.")
    else:
        print("The string is not a palindrome.")

check_palindrome()