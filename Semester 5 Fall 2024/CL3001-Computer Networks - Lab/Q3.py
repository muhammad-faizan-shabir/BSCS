def isNonAlphabetWord(word):
    for ch in word:
        if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z')):
            return False
    return True

def main():
    outputFile= open("OutputPartC",'w')
    
    with open("file.txt",'r') as f:
        for line in f:
            words=line.split()
            for word in words:
                if(isNonAlphabetWord(word)==True):
                    outputFile.write(word)
                    outputFile.write(" ")
            outputFile.write("\n")
    
            
    outputFile.close()




main()
