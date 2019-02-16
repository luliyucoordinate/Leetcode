from functools import lru_cache
class Solution:
    def PredictTheWinner(self, nums: 'List[int]') -> 'bool':
        @lru_cache()
        def selectNumber(l, r):
            if l == r: 
                return nums[l]
            return max(nums[l] - selectNumber(l+1, r), nums[r] - selectNumber(l, r-1))
        return True if selectNumber(0, len(nums)-1) >= 0 else False