# coding=utf-8
# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.


# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    n = len(A)

    forward = [0] * n
    backward = [0] * n

    # we allow the best to be 0 if all negative
    local_sum = 0

    for i in range(1, n - 1):  # 1 to n-2
        local_sum = max(0, local_sum + A[i])
        forward[i] = local_sum

    local_sum = 0
    for i in range(n - 2, 0, -1):
        local_sum = max(0, local_sum + A[i])
        backward[i] = local_sum

    maxresult = 0

    for i in range(1, n - 1):
        maxresult = max(maxresult, forward[i - 1] + backward[i + 1])

    return maxresult


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    A = [3, 2, 6, -1, 4, 5, -1, 2]
    print(solution(A))

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
