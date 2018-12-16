class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        result = list()
        nums_len = len(nums)
        if nums_len < 4:
            return result
        
        if nums[0] * 4 > target or nums[nums_len - 1] * 4 < target:
            return result

        nums_map = {}
        for i in range(nums_len-1, 0, -1):
            if i < nums_len - 1 and nums[i] == nums[i + 1]:
                continue
            for j in range(i-1, -1, -1):
                if j < i-1 and nums[j] == nums[j + 1]:
                    continue
                if nums[i] + nums[j] not in nums_map:
                    nums_map[nums[i] + nums[j]] = [[j, i]]
                else:
                    nums_map[nums[i] + nums[j]].append([j, i])

        for i in range(nums_len - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i+1, nums_len - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                
                dif = target - nums[i] - nums[j]
                if dif not in nums_map:
                    continue
                else:
                    for num in nums_map[dif]:
                        if num[0] > j:
                            result.append([nums[i], nums[j], nums[num[0]], nums[num[1]]])
        return result

if __name__ == '__main__':
    nums = [1,0,-1,0,-2,2]
    target = 0
    print(Solution().fourSum(nums, target))