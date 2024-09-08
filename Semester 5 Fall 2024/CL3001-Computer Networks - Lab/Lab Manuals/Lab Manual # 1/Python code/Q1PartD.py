
def containsVowels(word):
    for ch in word:
        if(ch in ['a','e','i','o','u','A','E','I','O','U']):
            return True
    return False
        
def invert(word):
    e=len(word)-1
    reversedString=""
    while(e>=0):
        reversedString= reversedString + word[e]
        e=e-1
    return reversedString

def main():
    outputFile= open("PartD_Output.txt",'w')
    
    with open("Input File.txt",'r') as f:
        for line in f:
            words=line.split()
            for word in words:
                if(containsVowels(word)==True):
                    outputFile.write(invert(word))
                else:
                    outputFile.write(word)
                outputFile.write(" ")
            outputFile.write('\n')
        
    outputFile.close()





main()
