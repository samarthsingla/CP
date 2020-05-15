import math
from matplotlib import pyplot as plt
plt.style.use('dark_background')
#Point class to store the point
class Point:
    def __init__(self, xx, yy):
        self.x = xx
        self.y = yy

#Variables
a = []
opt = []#optimal partition costs
c = 30#cost of adding a partition
part = []

prefx = []
prefy = []
prefxy = []
prefx2 = []

def dist(m, c, pt):
    num = abs((m*pt.x) - pt.y + c)
    den = math.sqrt((m**2) + 1)
    return num/den
#Error for line of best fit from point i->j
def error(i, j):
    mn = (n*(prefxy[j] - prefxy[i] + (a[i].x*a[i].y))) - ((prefx[j]-prefx[i]+a[i].x)*(prefy[j]-prefy[i]+a[i].y))
    md = (n*(prefx2[j]- prefx2[i] + (a[i].x ** 2))) - ((prefx[j]-prefx[i]+a[i].x)**2)
    if md != 0:
        m = mn/md
    c = ((prefy[j]-prefy[i]+a[i].y) - (m*(prefx[j]-prefx[i]+a[i].x)))/n
    e = 0
    for k in range(i, j+1):
        e += dist(m, c, a[k])
    return e, m, c
n = int(input())
#Input
x,y = map(float, input().split())
a.append(Point(x,y))
prefx.append(x)
prefy.append(y)
prefxy.append(x*y)
prefx2.append(x**2)
for i in range(n-1):
    x, y = map(float, input().split())
    a.append(Point(x,y))
    prefx.append(prefx[-1] + x)
    prefy.append(prefy[-1] + y)
    prefxy.append(prefxy[-1] + (x*y))
    prefx2.append(prefx2[-1] + (x**2))

#Main
opt.append(0)
for i in range(1, n):
    opt.append(error(0, i)[0] + c)
    for j in range(1, i):
        opt[i] = min(opt[i], c + error(j,i)[0] + opt[j-1])
print(opt[n-1])

#Backtrace the tracks
def backtrace(i):
    if i > 0 :
        minj, minyet = i, math.inf
        for j in range(0, i):
            if  c + error(j,i)[0] + opt[j] < minyet:
                minyet = c + error(j,i)[0] + opt[j]
                minj = j
        #add a partitioning line between min j and i
        line = error(minj, i)
        part.append((line[1], line[2]))#append a line(tuple of m and c)
        backtrace(minj -1)

def plotlines():
    first = a[0].x - 1
    last = a[n-1].x + 1
    for line in part:
        plt.plot([first, last], [getcoor(line, first), getcoor(line, last)])
def getcoor(line, xcoord):
    m, c = line[0], line[1]
    return (m*xcoord + c)
backtrace(n-1)
plotlines()
print(part)
plt.scatter([p.x for p in a], [p.y for p in a])
plt.show()