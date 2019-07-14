class Solution:
    def canDivideIntoSubsequences(self, nums: List[int], K: int) -> bool:
        return len(nums) >= K * max(collections.Counter(nums).values())