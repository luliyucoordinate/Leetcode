class Solution:
    def _sortColors(self, nums, l, r):
        if r <= l: return
        lt = l
        gt = r + 1
        i = l + 1
        while i < gt:
            if nums[i] < nums[l]:
                lt += 1
                nums[i], nums[lt] = nums[lt], nums[i]
                i += 1
                
            elif nums[i] > nums[l]:
                gt -= 1
                nums[i], nums[gt] = nums[gt], nums[i]
                
            else:
                i += 1
        nums[l], nums[lt] = nums[lt], nums[l]
        self._sortColors(nums, l, lt - 1)
        self._sortColors(nums, gt, r)

    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        self._sortColors(nums, 0, len(nums) - 1)


if __name__ == "__main__":
    arr = [2,0,2,1,1,0]
    Solution().sortColors(arr)
    print(arr)