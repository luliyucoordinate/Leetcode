class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = list()
        candidates.sort()
        self._combinationSum2(candidates, target, 0, list(), result)
        return result
        
    def _combinationSum2(self, nums, target, index, path, res):
        if target == 0:
            res.append(path)
            return 

        if path and target < path[-1]:
            return
       
        for i in range(index, len(nums)):
            if i > index and nums[i] == nums[i - 1]:
                continue
            self._combinationSum2(nums, target-nums[i], i + 1, path+[nums[i]], res)


if __name__ == '__main__':
    candidates = [10,1,2,7,6,1,5]
    target = 8
    print(Solution().combinationSum2(candidates, target))