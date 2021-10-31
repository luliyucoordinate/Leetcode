class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = cnt = 0
        for num in nums:
            if cnt == 0:
                res = num
            cnt += 1 if res == num else -1
        return res
        
if __name__ == "__main__":
    nums = [2,2,1,1,1,2,2]
    print(Solution().majorityElement(nums))