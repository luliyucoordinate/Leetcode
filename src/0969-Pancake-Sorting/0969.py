class Solution:
    def pancakeSort(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        res = list()
        for i in range(len(A), 1, -1):
            idx = A.index(i)
            A = A[:idx:-1] + A[:idx]
            res += [idx + 1, i]
            
        return res