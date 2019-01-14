class Solution:
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pre_sum, res = 0, 0
        dic = {0:-1}
        
        for i in range(len(nums)):
            pre_sum += -1 if nums[i] == 0 else 1
            if pre_sum in dic:
                res = max(res, i - dic[pre_sum])
            else:
                dic[pre_sum] = i
                
        return res