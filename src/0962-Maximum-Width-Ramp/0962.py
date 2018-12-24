class Solution:
    def maxWidthRamp(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        stack = list()
        res = 0
        for i, a in enumerate(A):
            if not stack or A[stack[-1]] > a:
                stack.append(i)
                
        for j in range(len(A))[::-1]:
            while stack and A[stack[-1]] <= A[j]:
                res = max(res, j - stack.pop())
                
        return res