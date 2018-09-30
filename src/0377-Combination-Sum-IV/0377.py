class Solution:
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """ 
        mem = dict()
        nums.sort()
        return self._combinationSum4(nums, target, mem)
        
    def _combinationSum4(self, nums, target, mem):
        if target == 0:
            return 1

        if target in mem:
            return mem[target]

        result = 0
        for num in nums:
            if num > target:
                break
            result += self._combinationSum4(nums, target - num, mem)

        mem[target] = result
        return result

if __name__ == '__main__':
    nums = [1, 2, 4]
    target = 32
    print(Solution().combinationSum4(nums, target))