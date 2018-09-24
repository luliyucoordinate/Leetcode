class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pre, cur = 0, 0
        for i in nums:
            pre, cur = cur, max(pre + i, cur)

        return cur

if __name__ == '__main__':
    nums = [2,7,9,3,1]
    print(Solution().rob(nums))