class Solution:
    def minKBitFlips(self, A: 'List[int]', K: 'int') -> 'int':
        cur = res = 0
        for i in range(len(A)):
            if i >= K:
                cur -= A[i - K] // 2
            if (cur + A[i]) & 1 == 0:
                if i + K > len(A):
                    return -1
                A[i] += 2
                cur, res = cur + 1, res + 1
        return res