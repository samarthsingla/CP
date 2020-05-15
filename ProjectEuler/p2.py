for t in range(int(input())):
    n, d = map(int, input().split())
    x = [int(s) for s in input().split()]
    latest = d
    for i in range(n-1, -1, -1):
        latest = (x[i] * (latest // x[i]))
    print("Case #{}: {}".format(t+1, latest))