# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.
from typing import List

def trap(height: List[int]) -> int:
        if len(height) <= 2:
            return 0

        left = []
        right = []

        maxleft = height[0]
        maxright = height[-1]

        for i in range(1, len(height) - 1):
            left.append(maxleft)
            if maxleft < height[i]:
                maxleft = height[i]

            right = [maxright] + right
            if maxright < height[len(height) - 1 - i]:
                maxright = height[len(height) -1 - i]

        #print(left)
        #print(right)
        res = 0

        for i in range(1, len(height) - 1):
            drop = min(left[i-1], right[i-1])
            if drop - height[i] > 0:
                res += drop - height[i]

        return res


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(trap(height))

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
