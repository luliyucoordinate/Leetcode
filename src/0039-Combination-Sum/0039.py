class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = list()
        candidates.sort()
        self._combinationSum(candidates, target, 0, list(), result)
        return result
        
    def _combinationSum(self, nums, target, index, path, res):
        if target == 0:
            res.append(path)
            return 

        if path and target < path[-1]:
            return

        for i in range(index, len(nums)):
            self._combinationSum(nums, target-nums[i], i, path+[nums[i]], res)

if __name__ == '__main__':
    candidates = [2,3,5]
    target = 8
    print(Solution().combinationSum(candidates, target))