class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = (low + high) // 2
            if nums[low] <= nums[mid]:
                if nums[mid] <= nums[high]:
                    return nums[low]
                else:
                    low = mid + 1
            else:
                if nums[mid] <= nums[high]:
                    high = mid

        return -1 
        
if __name__ == "__main__":
    nums = [3,1,2]
    print(Solution().findMin(nums))