class Solution:
    def _permuteUnique(self, nums, i, result):
        if i == len(nums) - 1:
            result.append(nums.copy())
            return         

        for k in range(i, len(nums)):
            if i != k and nums[i] == nums[k]:
                continue
            nums[i], nums[k] = nums[k], nums[i]
            self._permuteUnique(nums.copy(), i + 1, result)
                
        
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = list()
        self._permuteUnique(nums, 0, result)
        return result

if __name__ == '__main__':
    nums = [1,1,2]
    print(Solution().permuteUnique(nums))