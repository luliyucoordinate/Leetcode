class Solution:
    def maxTurbulenceSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res, anchor = 1, 0
        A_len = len(A)
        for i in range(1, A_len):
            if A[i] == A[i-1]:
                anchor = i
                continue
            if i == A_len - 1 or A[i-1] <= A[i] <= A[i+1] or A[i-1] >= A[i] >= A[i+1]:
                res = max(res, i - anchor + 1)
                anchor = i
        return res