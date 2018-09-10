class Solution:
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        result = list()
        nums = [i for i in range(1, 10)]
        self._combinationSum3(nums, n, 0, list(), result, k)
        return result

    def _combinationSum3(self, nums, target, index, path, res, k):
        if target == 0 and len(path) == k:
            res.append(path)
            return 
       
        for i in range(index, len(nums)):
            self._combinationSum3(nums, target-nums[i], i + 1, path+[nums[i]], res, k)

# class Solution(object):
#     def combinationSum3(self, k, n):
#         """
#         :type candidates: List[int]
#         :type target: int
#         :rtype: List[List[int]]
#         """
#         return [x for x in itertools.combinations(range(1, 10), k) if sum(x) == n]

if __name__ == '__main__':
    k, n = 3, 9
    print(Solution().combinationSum3(k, n))