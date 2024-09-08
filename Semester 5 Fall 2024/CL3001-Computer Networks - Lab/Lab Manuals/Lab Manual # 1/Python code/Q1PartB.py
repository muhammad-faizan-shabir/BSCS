def main():
    outputFile=open("PartB_Output.txt",'w')
    
    with open("Input File.txt", 'r') as f:
        for line in f:
            
            words=line.split()
            
            for word in words:
                
                printSpace=False
                for ch in word:
                    if(ch>='0' and ch<='9'):
                        outputFile.write(ch)
                        printSpace=True
                
                if(printSpace==True):
                    outputFile.write(" ")
            outputFile.write("\n")
    outputFile.close()
                
        
    
    




main()
