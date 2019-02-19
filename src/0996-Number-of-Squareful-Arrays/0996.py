class Solution:
    def numSquarefulPerms(self, A: 'List[int]') -> 'int':
        n = len(A)
        res = 0
        def permute(nums, i):
            nonlocal res
            if i == n:
                res += 1
                return 
            for k in range(i, n):
                if i != k and nums[i] == nums[k]:
                    continue
                nums[i], nums[k] = nums[k], nums[i]
                if i == 0 or int((nums[i] + nums[i-1])**(0.5))**2 == (nums[i] + nums[i-1]):
                    permute(nums.copy(), i+1)
                
        A.sort()
        permute(A, 0)
        return res