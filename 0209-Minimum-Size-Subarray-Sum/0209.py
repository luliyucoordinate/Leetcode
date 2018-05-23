class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        l = 0
        r = -1
        sum_all = 0
        nums_len = len(nums)
        res = nums_len + 1
        while l < nums_len:
            if r + 1 < nums_len and sum_all < s:
                r += 1
                sum_all += nums[r]
            else:
                sum_all -= nums[l]
                l += 1
            
            if sum_all >= s:
                res = min(res, r - l + 1)

        if res == nums_len + 1:
            return 0
        
        return res
        

if __name__ == "__main__":
    arr = []
    target = 7
    print(Solution().minSubArrayLen(target, arr))