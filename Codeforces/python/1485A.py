import math

def helper(a,b):
    r = math.log(a,b)
    return int(r)

def solve():
    s = input()
    [a,b] = s.split()

    a = int(a)
    b = int(b)

    if a < b:
        return 1

    if a == b:
        return 2

    if b == 1:
        return 1 + helper(a,2)

    l = helper(a, b)

    res = l

    for i in range(30):
        temp = i + helper(a, b + i)

        if temp < res:
            res = temp

    print(res)



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print(int(math.log(571787, 83)))
    tc = int(input())
    while tc > 0:
        solve()
        tc -= 1