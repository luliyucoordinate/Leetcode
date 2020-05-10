class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxd, mind, i = [], [], 0
        
        for a in nums:
            while maxd and a > maxd[-1]: maxd.pop()
            while mind and a < mind[-1]: mind.pop()
            maxd.append(a)
            mind.append(a)
            if maxd[0] - mind[0] > limit:
                if maxd[0] == nums[i]: maxd.pop(0)
                if mind[0] == nums[i]: mind.pop(0)
                i += 1
        return len(nums) - i