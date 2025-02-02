# Task 6
def removeVowels():
    vowels=['a','e','i','o','u','A','E','I','O','U']
    
    string= input("Enter a string: ")
    updatedString=""
    
    for ch in string:
        if(ch not in vowels):
            updatedString= updatedString + ch
    
    print("String with vowels removed:",updatedString)

removeVowels()