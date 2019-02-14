class Solution:
    def subarraysWithKDistinct(self, A: 'List[int]', K: 'int') -> 'int':
        m = [0]*(len(A) + 1)
        j, prefix, cnt, res = 0, 0, 0, 0
        for i in range(len(A)):
            if m[A[i]] == 0:
                cnt += 1
            m[A[i]] += 1
                
            if cnt > K:
                m[A[j]] -= 1
                j += 1
                cnt -= 1
                prefix = 0
                
            while m[A[j]] > 1:
                prefix += 1
                m[A[j]] -= 1
                j += 1
                
            if cnt == K:
                res += prefix + 1
        return res