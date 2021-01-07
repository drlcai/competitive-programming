def consecutiveNumbersSum(N: int) -> int:
    nums = []

    ptr = 1
    sums = 0
    while sums < N:
        nums += [sums]
        sums += ptr
        ptr += 1

    res = 0
    for i in range(len(nums)):
        if (N - nums[i]) % (i + 1) == 0:
            res += 1
            # print ( (N - nums[i]) // (i + 1))
    # print(nums)
    return res

if __name__ == '__main__':
    N = 1000000000
    print( consecutiveNumbersSum(N) )