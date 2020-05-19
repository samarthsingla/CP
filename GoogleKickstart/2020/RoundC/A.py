for t in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    test = [k - i for i in range(k)]
    i = 0
    p = 0
    while i < n:
        if a[i] == k - p:
            p += 1
        else:
            p = 0
        if a[i] == k-p:
            p += 1
        if p == k:
            ans += 1
            p = 0
        i += 1
    print("Case #{}: {}".format(t+1, ans))