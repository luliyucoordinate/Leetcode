class Solution:
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        sum_nums = sum(nums)
        if sum_nums < S or (S + sum_nums)%2 != 0:
            return 0

        target = (S + sum_nums) >> 1
        mem = [0]*(target + 1)
        mem[0] = 1
        for num in nums:
            for i in range(target, num-1, -1):
                mem[i] += mem[i - num]
        return mem[target]


if __name__ == '__main__':
    nums = [1, 1, 1, 1, 1]
    S = 3
    print(Solution().findTargetSumWays(nums, S))