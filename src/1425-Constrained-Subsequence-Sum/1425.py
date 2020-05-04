class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        q, res = [], float("-inf")
        for i, v in enumerate(nums):
            nums[i] = max(v, v + (q[0] if q else 0))
            while q and nums[i] > q[-1]:
                q.pop()
            q.append(nums[i]) 

            if i >= k and q and q[0] == nums[i - k]:
                q.pop(0)
            res = max(res, nums[i])
        return res