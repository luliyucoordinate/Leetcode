class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = j = r = len(nums) - 1
        while i > 0 and nums[i] <= nums[i-1]:
            i -= 1
            
        i -= 1
        if i >= 0:
            while j >= i and nums[j] <= nums[i]:
                j -= 1

            nums[i], nums[j] = nums[j], nums[i]
            
        i += 1      
        while i < r:
            nums[i], nums[r] = nums[r], nums[i]
            i += 1
            r -= 1



if __name__ == "__main__":
    nums = [3,2,1]
    Solution().nextPermutation(nums)
    print(nums)