class Solution:
    def sumSubarrayMins(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res = 0
        stack = []
        A = [0] + A + [0]
        for i, x in enumerate(A):
            while stack and A[stack[-1]] > x:
                j = stack.pop()
                k = stack[-1]
                res += A[j] * (i - j) * (j - k)
            stack.append(i)
        return res % (10**9 + 7)