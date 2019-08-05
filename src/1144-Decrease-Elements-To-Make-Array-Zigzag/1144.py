class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        nums = [float("inf")] + nums + [float("inf")]
        res = [0, 0]
        for i in range(1, len(nums) - 1):
            res[i % 2] += max(0, nums[i] - min(nums[i - 1], nums[i + 1]) + 1)
        return min(res)