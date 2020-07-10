arr = [3, 5, 10]
n = int(input())
l = len(arr)

def count(arr, l, n):

    # we made table to store the ways of making value x
    # it is of size n+1 because considering 0 value as start
    # initializing all values in table as 0 i.e. 0 ways to make that value
    table = [[0 for x in range(l)] for x in range(n + 1)]

    # if value is 0 then number of ways making it is 1 (n=0)
    for i in range(l):
        table[0][i] = 1

    for i in range(1, n+1):
        for j in range(l): 

            if i-arr[j] >= 0:
                x = table[i - arr[j]][j]
            else:
                x = 0

            if j >= 1:
                y = table[i][j-1]  
            else:
                y = 0

            # total 
            table[i][j] = x + y

    return table[n][l-1]

print(count(arr, l, n))
