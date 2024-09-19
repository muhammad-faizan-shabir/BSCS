def main():
    sentence = input("Enter a sentence: ")
    
    print ("Uppercase: " , sentence.upper())
    print ("Lowercase: " , sentence.lower())
    
    words = sentence.split()
    print ("Number of words: ", len(words))

    print ("Title Case: ",end="")
    for i in range(0,len(words)):
        char = words[i][0].upper()
        words[i] =  char + words[i][1::]

    for word in words:
        print (word+" ",end="")
    
    print("")

main()