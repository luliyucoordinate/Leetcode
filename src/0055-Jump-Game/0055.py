class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        m = 0
        for i, num in enumerate(nums):
            if i > m:
                return False
            m = max(m, i + num)
        return True

if __name__ == "__main__":
    nums = [2,3,1,1,4]
    print(Solution().canJump(nums))