from functools import reduce
from operator import xor
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mask = reduce(xor, nums)
        mask &= -mask
        result = [0]*2
        for num in nums:
            if num & mask:
                result[0] ^= num
            else:
                result[1] ^= num

        return result

if __name__ == "__main__":
    nums = [1,2,1,3,2,5]
    print(Solution().singleNumber(nums))