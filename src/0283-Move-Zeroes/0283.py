class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        k = 0
        for i, num in enumerate(nums):
            if num != 0:
                if i != k:
                    nums[i], nums[k] = nums[k], nums[i]
                    k += 1
                else: #i == k
                    k += 1
                    
if __name__ == "__main__":
    arr = [0, 1, 0, 3, 12]
    Solution().moveZeroes(arr)
    print(arr)