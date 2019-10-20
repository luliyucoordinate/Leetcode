class Solution:
    def minAvailableDuration(self, A: List[List[int]], B: List[List[int]], duration: int) -> List[int]:
        A.sort()
        B.sort()
        i = j = 0
        while i < len(A) and j < len(B):
            l = max(A[i][0], B[j][0])
            r = min(A[i][1], B[j][1])
            if l + duration <= r:
                return [l, l + duration]
                
            if A[i][1] < B[j][1]:
                i += 1
            else:
                j += 1
                
        return []