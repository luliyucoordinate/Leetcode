class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 1

        max_len = max(nums)+1
        mem = [0]*max_len
        mem[0] = 1
        for num in nums:
            if num > 0:
                mem[num] = 1

        for i, val in enumerate(mem):
            if val != 1:
                return i

        return max_len

        
if __name__ == "__main__":
    nums = [3,4,-1,1]
    print(Solution().firstMissingPositive(nums))