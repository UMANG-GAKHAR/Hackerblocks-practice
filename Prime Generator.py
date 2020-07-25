'''

t = int(input())

while t != 0:
    m, n = [int(x) for x in input().split()]

    for i in range(m, n + 1):
        if i == 1:
            continue
        flag = 1

        for j in range(2, i//2 + 1):
            if (i % j) == 0:
                flag = 0
                break

        if flag == 1:
            print(i, end=' ')
    print("\n")
    t -= 1
'''

def checkPrime(num):
    if num==0 or num==1 :
        return False
    elif num==2 :
        return True
    elif num%2==0 :
        return False
    else :
        i=2
        while(i*i<=num):
            if(num % i==0):
                return False
            i=i+1
        return True
        
            
    

T = int(input())
while(T>0):
    l = [int(i) for i in (input().split())]
    x = l[0]
    y = l[1]
    
    for i in range(x,y+1):
        if (checkPrime(i)):
            print(i,end=" ")
            
    print()
    
    T -= 1
