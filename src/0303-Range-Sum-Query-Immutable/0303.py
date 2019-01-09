from itertools import accumulate
class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = [0]+list(accumulate(nums))

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.nums[j+1] - self.nums[i]