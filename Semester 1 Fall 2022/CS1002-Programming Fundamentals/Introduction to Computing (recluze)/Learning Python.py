import math
import time
from math import sqrt
from math import pi
from re import X
from tkinter import Y
from xmlrpc.client import boolean


def square(x=2):
    return x*x

def sum_squares(x,y):
    return square(x)+square(y)

def fun1(self):
    print("hello")
    print("yes")
    
    

def fib(n):
    a=[0,1]
    
    if(n<=1):
        return a[n]
    for i in range(2,n+1):
        x=a[i-1]+a[i-2]
        a.insert(i,x)
 
    return a[n]
    
def onefinder(string): 
    left = 0
    right = len(string) - 1
    onecounter = 0

    while left <= right:
        
        mid = (left + right) // 2

        if string[mid] == '0':
            left = mid + 1
        elif string[mid] == '1':
            onecounter += right - mid + 1
            right = mid - 1
        

    return onecounter
    
    
    
    
y=5

class animal:
    def __init__(self):
        self.x=4
        #print("Parent")
    def fun(self):
        print("Parent fun")
        
    def __str__(self):
        return "__str__"
        
class dog(animal):
    def __init__(self):
        super().__init__()
        print(self.x)
def main():
    #print(max(min(1,-2),min(pow(3,5),-4)))
    #print(sqrt(256))
    
    #help(math.sqrt)
    #x=24
    #print(type(x))
    #x=6.0
    #print(type(x))
    #print(pi)
    #f= sqrt
    #print(f(256))
    #print(square(10))
    #print(sum_squares('a',4))
    #x=5
    #print(id(x))
    #fun1(x)
    #y=x
    #z=y
    #y=5
    #print(id(y))
    #print(id(z))
    #y='a'*2
    #print(y)
    #print(type(y))
    #a = min
    #b= max
    #y= a(1,b(2,4))
    #print(y)
    
    #print(y)
    #fun1()
    #print(y)
    #print(help(fun1))
    #for i in range (1,10):
     #   for j in range (1,2):
      #      if(i ==1):
       #         break
        #    print ("inside")
        #print("outside")
    #print(fib(10))
    #a =[1,2,3]
    #print(a)
    #b=a
    #b[0]=10
    #print(a)
    #help(list.append  )
    #a=range(1,10)
    #print(a)
    #a = (1,'a',None,4.235)
    #print(a)
    #a[3]=33\
    #print(id(a),id(b))
    #a=[1,2,3]
    #b=[4,6,5]
    #x=4
    #for i in x:
        
     #   print(i)
    #print(list(range(1,10)))
    #print(7/2)
    #string ='01111111'
    #print(onefinder(string))
    #print("az">"ac")
    #a={1:9,"dk": "oh yea"}
    #print(a[1])
    #a["dk"]= "kfdkf" 
    #print(a)
    #for i in a:
     #   print (a[i])
    #print(type("ksk"))
    
    #l=5
    #print(id(l))
    #l=5
    #print(id(l))
    #v="12"
    #print(v)
    #c=int(v)
    #print(c+3)
    #rint(v+"34")
    #print(int("-45"))
    
    
    #b=101
    #a=b+1
    #print(id(b),id(a))
    
    #print(a == False)
    #a=animal()
    #print(id(a))
    
    #a.legs=80
    #print(id(a))
    
    #a=5
    #print(id(a))
    #a=8
    #print(id(a))
    #l=[1,2,3]
    #a=[5,6,7]
    #l[0]=a[0]
    #l[1]=a[1]
    #l[2]=a[2]
    #l=a
    #print(id(l))
    #print(id(a))

    #d= dog()
    #d.fun()
    #raise IndexError("not fair")
    #assert 1==2,4444
    #print("recahed")
    #x=2
    #y=34
    #print("%2d" % x)
    #print("{1:03} and {0:03}".format(y,x))
    #print("x=%.2f and y=%d" % (x,y))
    #print("x={} and y={}".format(x,y))
    #s="Test"
    #print("[%10s]"%s)
    #print("[{:>10}]".format(s))
    #l=[[1,2,3],[4,5,6]]
    #k=[l[0][:],l[1][:]]
    #k=l[:]
    #k[0] =["hi","hello"]
    #k[0][0]=23
    #print(l)
    #print(k)
    #s="hello"
    #s[0]='a'
    #l=(1,2,3)
    #l[0]=10

    #X = np.linspace(1,10,40)
    #print(X)
    #help(print)
    #print(flush=True)
    #s=",,hello,,,,,,"
    #a=s.strip(',')
    #print (a)
    animal.fun1=fun1
    a= animal()
    #p=fun1
    #print(id(a.fun1))
    #print(id(fun1))
    #print(id(p))
    print(a,end=' '),print(" yes")
    
    
    



main()
#print("Hello world")