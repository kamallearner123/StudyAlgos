from functools import reduce
def get_high(a, nums):
    print("inpu = ", a)
    a.sort(reverse=True)
    result = reduce(lambda x,y:x*y, a[:3])
    if a[-1]<0 and a[-2]<0:
        if a[-1]*a[-2]*a[0] > result:
            print(a[-1],a[-2],a[0])
            result = a[-1]*a[-2]*a[0]
        else:
            print(a[:3])
    else:
        print(a[:3])
    return result

print(get_high([3,5,77,0,-2], 3))
print(get_high([3,5,77,-100,-2], 3))
print(get_high([-3,-5,-77,-100,-1], 3))
