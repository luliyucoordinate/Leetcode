class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        r, c = len(A), len(A[0])
        mem = [1] * c
        for i in range(1, c):
            for j in range(i):
                for k in range(r+1):  
                    if k == r:
                        mem[i] = max(mem[i], mem[j] + 1)
                    elif A[k][j] > A[k][i]:
                        break
                        
        return c - max(mem)