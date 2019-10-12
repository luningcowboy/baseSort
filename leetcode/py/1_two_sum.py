"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""

def solution_0(nums, target):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            n1 = nums[i]
            n2 = nums[j]
            if n1 + n2 == target:
                return [i, j]

def solution_1(nums, target):
    lookup = {}
    for i, n in enumerate(nums):
        if target - n in lookup:
            return [i,lookup[target-n]]
        else:
            lookup[n] = i

print(solution_0([2,7,11,15], 9))
print(solution_1([2,7,11,15], 9))
