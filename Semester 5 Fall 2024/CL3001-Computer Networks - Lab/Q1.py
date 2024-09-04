def main():
    f = open("file.txt",'r')
    
    for line in f:
        print (line,end="")
    
    print ('\n')
        
    f.close()
    

main()
    

