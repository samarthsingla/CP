import math
def dist(m, c, pt):
    num = abs((m*pt.x) - pt.y + c)
    den = math.sqrt((m**2) + 1)
    return num/den

class Point:
    def __init__(self, xx, yy):
        self.x = xx
        self.y = yy

pt = Point(1,0)
print(dist(1, 0, pt))