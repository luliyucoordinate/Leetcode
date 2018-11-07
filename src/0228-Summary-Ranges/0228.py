class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        nums_len = len(nums)
        if nums_len == 0:
            return []
        result = list()
        start, end, pre, cur = 0, 0, 0, 1
        while cur <= nums_len:
            if cur < nums_len and nums[cur] - nums[pre] == 1:
                cur += 1
                pre += 1
            else:
                end = pre
                if end != start:
                    result.append(str(nums[start])+"->"+str(nums[end]))
                else:
                    result.append(str(nums[start]))
                start = cur
                cur += 1
                pre += 1

        return result
        
if __name__ == "__main__":
    nums = [0,2,3,4,6,8,9]
    print(Solution().summaryRanges(nums))