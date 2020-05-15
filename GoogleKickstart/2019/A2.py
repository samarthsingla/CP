from math import inf
from collections import deque
def valid(r, c, t):
    i, j = t[0], t[1]
    if i >= r or i < 0 or j >= c or j < 0:
        return False
    else:
        return True
for t in range(int(input())):
    r, c = map(int, input().split())
    m = []
    q = deque()
    a = [[inf for j in range(c)] for i in range(r)]
    for i in range(r):
        m.append(list(map(int, input().split())))
    for i in range(r):
        for j in range(c):
            if m[i][j] == 1:
                a[i][j] = 0
                q.append((i,j)) #added a new source to start bfs

    #multisource bfs for O(RC) search
    d = None
    while(len(q) > 0):
        s = q.pop()
        x, y = s[0], s[1]
        d = a[x][y] + 1
        adj = [(x+1, y), (x, y+1), (x-1, y), (x, y-1)]
        for cell in adj:
            if valid(r, c, cell):
                if a[cell[0]][cell[1]] > d:
                    a[cell[0]][cell[1]] = d
                    q.append((cell[0],cell[1]))
