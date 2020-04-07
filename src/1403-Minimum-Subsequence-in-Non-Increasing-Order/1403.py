class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)
        res, cur, t = [], 0, sum(nums) / 2
        
        for i in nums:
            cur += i
            res.append(i)
            if cur > t: return res
        return res