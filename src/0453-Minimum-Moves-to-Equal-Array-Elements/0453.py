class Solution:
    def minMoves(self, nums: List[int]) -> int:
        min_num = min(nums)
        res = 0
        for num in nums:
            res += num - min_num
        return res