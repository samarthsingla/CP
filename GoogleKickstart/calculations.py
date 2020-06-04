# from math import sqrt
# v = sqrt((6.5*0.3*0.3/0.06) - (9.81*0.3))
# ans = ((v*sqrt(3)/2) * ((v/2) + sqrt(((v**2)/4) + (9*9.81))))/9.81
# print(ans)
# print(1/(sqrt(6) - sqrt(5)))
# print((997/1.23)**(1/3))
#
# print((15 * 1000000)/(18*20.3*20.3))
a = []
a.append(0)
for i in range(100):
    a.append((10/11) * (1+a[i]))
    print(a[i])