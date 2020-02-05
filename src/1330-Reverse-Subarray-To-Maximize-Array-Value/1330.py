class Solution:
    def maxValueAfterReverse(self, nums: List[int]) -> int:
        total, res, Hi, Lj = 0, 0, float('inf'), -float('inf')
        for a, b in zip(nums, nums[1:]):
            total += abs(a - b)
            Hi, Lj = min(Hi, max(a, b)), max(Lj, min(a, b))
            res = max(res, abs(nums[0] - b) - abs(a - b), \
                      abs(a - nums[-1]) - abs(a - b), \
                     (Lj - Hi) * 2)
        return total + res