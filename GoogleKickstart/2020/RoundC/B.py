from collections import deque
for t in range(int(input())):
    r, c = map(int, input().split())
    w = []
    for i in range(r):
        w.append(list(input().split()))

    for i in range(c):
        