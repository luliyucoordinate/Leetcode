class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums:
            return list()
        
        res, stack = list(), list()
        for i, val in enumerate(nums):
            while stack and nums[stack[-1]] < val:
                stack.pop()
                
            stack.append(i)
            if i - stack[0] >= k:
                stack.pop(0)
            if i >= k - 1:
                res.append(nums[stack[0]])
           
        return res