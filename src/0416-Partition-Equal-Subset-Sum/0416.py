class Solution:
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        result = sum(nums)

        if result%2 != 0:
            return False

        return self._canPartition(nums, len(nums) - 1, result/2)

    def _canPartition(self, nums, index, result):
        if result == 0:
            return True

        if result < 0 or index < 0 or nums[index] > result:
            return False

        return self._canPartition(nums, index - 1, result - nums[index]) or \
            self._canPartition(nums, index - 1, result)
            
if __name__ == '__main__':
    nums = [1, 5, 11, 5]
    print(Solution().canPartition(nums))