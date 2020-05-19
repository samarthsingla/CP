import math
for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    pref = []
    pref.append(a[0])
    for i in range(1,n):
        pref.append(pref[i-1] + a[i])
    ans = 0
    for r in range(n):
        for l in range(r+1):
            s = pref[r] - pref[l] + a[l]
            if s >= 0:
                if s % 4 == 0 or s % 4 == 1:
                    if math.floor(math.sqrt(s)) ** 2 == s:
                        ans += 1
    print("Case #{}: {}".format(t+1, ans))