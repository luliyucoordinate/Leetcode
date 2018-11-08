class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        return n*(n+1)// 2 - sum(nums)

if __name__ == "__main__":
    nums = [3,0,1]
    print(Solution().missingNumber(nums))