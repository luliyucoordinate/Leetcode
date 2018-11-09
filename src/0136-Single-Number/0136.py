class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for num in nums:
            result ^= num

        return result

if __name__ == "__main__":
    nums = [2,2,1]
    print(Solution().singleNumber(nums))