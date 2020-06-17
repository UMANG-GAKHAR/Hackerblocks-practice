import math
n = int(input())
for i in range(n):
    inp = int(input())
    for j in range(int(math.sqrt(inp)) + 1):
        for k in range(j, int(math.sqrt(inp)) + 1):
            if(j ** 2 + k ** 2 == inp):
                print('(' + str(j) + ',' + str(k) + ')', end = " ")
    print() 
