def opt_permutation(a):
    print("Original = ", a)
    length = len(a)
    cur=0
    count = 0
    while cur<length:
        if a[cur] == 0:
            a[cur] = 1
            count += 1
            for i in range(1, length-cur-1):
                a[cur+i] = 1 if a[cur+i] == 0 else 0 
            print(" a = ", a)
        else:
            cur += 1
            continue
    return count


def greedy(a):
    count = 0
    for i,val in enumerate(a):
        print(a)
        if count%2 == 1:
            a[i] = ~a[i]
        if a[i] == 1:
            continue
        else:
            a[i] = 1
            count += 1
    return count
a = [1,0,1,1,0,0,0,0]
print("a = ", a)
print("Count = ",greedy(a))
print(a)

