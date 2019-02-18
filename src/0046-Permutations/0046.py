class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res, n = list(), len(nums)
        def _permute(nums, i):
            if i == n:
                res.append(nums.copy())
                return
                
            for k in range(i, n):
                nums[i], nums[k] = nums[k], nums[i]
                _permute(nums, i + 1)
                nums[i], nums[k] = nums[k], nums[i]
        
        _permute(nums, 0)
        return res


if __name__ == '__main__':
    nums = [1,2,3,4]
    print(Solution().permute(nums))