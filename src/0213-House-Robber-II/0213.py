class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        if len(nums) == 1:
            return nums[0]

        pre1, cur1, pre2, cur2 = 0, 0, 0, 0
        for i in nums[:-1]:
            pre1, cur1 = cur1, max(pre1 + i, cur1)
        for i in nums[1:]:
            pre2, cur2 = cur2, max(pre2 + i, cur2)

        return max(cur1, cur2)

if __name__ == '__main__':
    nums = [2,3,2]
    print(Solution().rob(nums))