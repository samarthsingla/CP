m = 10**9
st = ""
n,w,s,e = 0,0,0,0
def rep(i, k):
    i+=2
    global n,s,w,e,st
    while st[i] != ")":
        ch = st[i]
        if ch in "23456789":
            i = rep(i, int(ch) * k)
        else:
            if ch == "N":
                n += k
            if ch == "S":
                s += k
            if ch == "W":
                w += k
            if ch == "E":
                e += k
        i+=1
    return i
for t in range(int(input())):
    st = input()
    i = 0
    while i < len(st):
        ch = st[i]
        if ch in "23456789":
            i = rep(i, int(ch))
        else:
            if ch == "N":
                n += 1
            if ch == "S":
                s += 1
            if ch == "W":
                w += 1
            if ch == "E":
                e += 1
        i += 1
    y = (1 + (s-n)) % m
    x = (1 + (e-w)) % m
    if y == 0:
        y = m
    if x == 0:
        x = m
    print("Case #{}: {} {}".format(t+1, x, y))
    n, w, s, e = 0, 0, 0, 0
