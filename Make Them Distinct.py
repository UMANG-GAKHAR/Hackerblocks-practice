t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    freq = [0]*(max(arr) + 1)

    for x in arr:
        freq[x] += 1

    if max(freq) > (len(arr) + 1) // 2:
        print("NO")
    else:
        print("YES")
