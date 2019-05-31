class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        return sum(nums[~i] - nums[i] for i in range(len(nums) // 2))