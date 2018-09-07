class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <= 1:
            return [nums]
        
        out = []
        perms = self.permute(nums[1:])
        for perm in perms:
            for i in range(0, len(perm)+1):
                p = perm[:i] + [nums[0]] + perm[i:]
                out.append(p)
        
        return out


if __name__ == '__main__':
    nums = [1,2,3]
    print(Solution().permute(nums))