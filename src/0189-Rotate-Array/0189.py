class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums_len = len(nums)
        k = nums_len - k%nums_len
        result = nums[:]
        for i in range(nums_len):
            nums[i] = result[(i+k)%nums_len]

if __name__ == "__main__":
    nums = [1,2,3,4,5,6,7] 
    k = 1
    Solution().rotate(nums, k)
    print(nums)