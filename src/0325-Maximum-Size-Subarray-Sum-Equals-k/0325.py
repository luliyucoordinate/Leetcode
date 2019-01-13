class Solution:
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: list
        :type k: int
        :rtype: int
        """
        pre_sum, res = 0, 0
        dic = dict()

        for i in range(len(nums)):
            pre_sum += nums[i]
            if pre_sum == k:
                res = i + 1
            elif pre_sum - k in dic:
                res = max(res, i - dic[pre_sum - k])
            if pre_sum not in dic:
                dic[pre_sum] = i

        return res

if __name__ == '__main__':
    nums = [1, -1, 5, -2, 3]
    k = 3
    print(Solution().maxSubArrayLen(nums, k))