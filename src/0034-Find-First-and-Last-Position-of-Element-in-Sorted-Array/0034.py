class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l, r = 0, len(nums)
        result = [-1,-1]
        while l < r:
            mid = (l+r)//2
            if nums[mid] >= target:
                if nums[mid] == target:
                    result[0] = mid
                r = mid
            else:
                l = mid + 1

        l, r = 0, len(nums)
        while l < r:
            mid = (l+r)//2
            if nums[mid] > target:
                r = mid
            else:
                if nums[mid] == target:
                    result[1] = mid
                l = mid + 1   

        return result

if __name__ == "__main__":
    nums = [5,7,7,8,8,10]
    target = 6
    print(Solution().searchRange(nums, target))