# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    # write your code in Python 3.6
    A.sort()

    lo = 0
    hi = len(A) - 1

    res = 2000000000
    while lo <= hi:
        res = min(res, abs(A[lo] + A[hi]))
        if abs(A[lo]) > abs(A[hi]):
            lo += 1
        else:
            hi -= 1

    return res

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    A = [3, 2, 6, -1, 4, 5, -1, 2]
    print(solution(A))