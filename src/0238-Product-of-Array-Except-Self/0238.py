class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums_len = len(nums)
        leftPro = [1]*len(nums)
        for i, num in enumerate(nums[:-1]):
            leftPro[i+1] = leftPro[i]*num

        right = 1
        for i in range(nums_len-1, -1, -1):
            leftPro[i] *= right
            right *= nums[i]
            
        return leftPro
        
if __name__ == "__main__":
    nums = [1,2,3,4]
    print(Solution().productExceptSelf(nums))