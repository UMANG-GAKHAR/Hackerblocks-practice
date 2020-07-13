T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    array_N = list(map(int, input().split()))
    array_M = list(map(int, input().split()))
    max_N = max(array_N)
    max_M = max(array_M)
    if max_N == max_M:
        print(str(max_N) + " Deepak")
    elif max_N < max_M:
        print(str(max_N) + " Deepak")
    else:
        print(str(max_M) + " Gautam")
