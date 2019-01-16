class Solution:
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        stack, nums_len = list(), len(nums)
        res = [-1] * nums_len
        for i in range(nums_len*2):
            while stack and nums[stack[-1]] < nums[i%nums_len]:
                res[stack.pop()] = nums[i%nums_len]
            stack.append(i%nums_len)
            
        return res