class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return [[]]
        result = self.subsets(nums[1:])
        return result + [[nums[0]] + s for s in result]


if __name__ == '__main__':
    nums = [1, 2, 3]
    print(Solution().subsets(nums))