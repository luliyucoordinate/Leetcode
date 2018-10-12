class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        result = list()
        nums.sort()
        for i,num in enumerate(nums[0:-2]):
            l, r = i + 1, len(nums) - 1
            if nums[l] + nums[l + 1] + num > target:
                result.append(nums[l] + nums[l + 1] + num)
            elif nums[r] + nums[r - 1] + num < target:
                result.append(nums[r] + nums[r - 1] + num)
            else:
                while l < r:
                    tmp_sum = nums[l] + nums[r] + num
                    result.append(tmp_sum)
                    if tmp_sum < target:
                        l += 1
                    elif tmp_sum > target:
                        r -= 1
                    else:
                        return target
        result.sort(key=lambda x:abs(x-target))
        return result[0]

if __name__ == "__main__":
    nums = [-1, 2, 1, -4]
    target = 1
    print(Solution().threeSumClosest(nums, target))