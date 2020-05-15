#https://codeforces.com/contest/1326/problem/A
t = int(input())
for _ in range(t):
    n = int(input())
    s = ""
    if n != 1:
        if(n % 3 == 1):
            s = "2" * (n-2)
            s = s + "33"
        else:
            s = "2"*(n-1)
            s + s + "3"
    else:
        s = "-1"
    print(s)