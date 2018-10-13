class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l, r = 0, len(nums)
        
        while l < r:
            mid = (r + l)//2
            if target > nums[mid]:
                l = mid + 1
            else:
                r = mid

        return l

if __name__ == "__main__":
    nums = [1, 3, 5, 6]
    target = 5
    print(Solution().searchInsert(nums, target))