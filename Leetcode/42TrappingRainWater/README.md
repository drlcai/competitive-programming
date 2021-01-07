Difficulty: Hard. Time: 15min

As a well-known problem, this is not so hard to code this problem, though I spent some time on thinking about the indices.
I should be able to solve them faster than 10min. 

The idea is simple, for a slot to store rain drops, we need to check the highest bar from the left and the highest bar from the right.
Then we use the min of them to subtract the height at the slot. Note that for the two end they don't store anyway.

The edge cases are when len(height) <= 2. Other than that we can always solve the problem without worring about anything. 

======

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining. 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

**Example 2:**

```
Input: height = [4,2,0,3,2,5]
Output: 9
```

 

**Constraints:**

- `n == height.length`
- `0 <= n <= 3 * 104`
- `0 <= height[i] <= 105`