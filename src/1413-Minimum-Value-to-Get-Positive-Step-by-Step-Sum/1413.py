class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        pref, min_pref = 0, 0
        for i in nums:
            pref += i
            min_pref = min(min_pref, pref)
        return 1 - min_pref