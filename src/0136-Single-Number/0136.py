from functools import reduce
from operator import xor
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(xor, nums)

if __name__ == "__main__":
    nums = [2,2,1]
    print(Solution().singleNumber(nums))