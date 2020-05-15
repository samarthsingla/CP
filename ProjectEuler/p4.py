C = None
R = None
l = None
u = None
r = None
d = None
dp = None
seen = None
def p(x, y):
    global dp, seen
    if x > d or y > r:
        return 1
    if x >= u and x <= d:
        if(y >= l and y <= r):
            return 0
    if seen[x][y]:
        return dp[x][y]
    else:
        dp[x][y] = 0.5 * (p(x+1,y) + p(x,y+1))
        return dp[x][y]
for t in range(int(input())):
    C, R, l, u, r, d = map(int, input().split())
    dp = [[0 for i in range(C)] for j in range(R)]
    seen = [[0 for i in range(C)] for j in range(R)]
    ans = p(1,1)
    print("Case #{}: {}".format(t+1, ans))
    C = None
    R = None
    l = None
    u = None
    r = None
    d = None
    dp = None
    seen = None