import math


def program():
    x = float(input())
    y = float(input())
    if x >= 0 and x <= 3:
        z = math.floor(x)*y
    else:
        z = x*y
    print(z)
