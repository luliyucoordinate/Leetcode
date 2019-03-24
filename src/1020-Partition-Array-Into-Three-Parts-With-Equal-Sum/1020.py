class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total, n = sum(A), len(A)
        if total%3 != 0:
            return False
        
        p = total//3
        tmp, t, res = 0, 0, 0
        for i in range(n):
            tmp += A[i]
            if tmp == p:
                tmp = 0
                res += 1
        return res >= 3