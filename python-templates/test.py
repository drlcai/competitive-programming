def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        s = input()

        if n == 1:
            print(0)
        else:
            ends = []
            dict = {}

            nums = s.split()

            ends += [int(nums[0])]
            for num in nums[1:]:
                # print(num)
                y = int(num)
                ends += [y]

            for j in range(len(ends) - 1):
                for k in range(j+1, len(ends)):
                    seg = ends[k] - ends[j]
                    if not seg in dict:
                        dict[seg] = 1
            print(len(dict))


if __name__ == "__main__":
    main()

