class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        def numOnes(row):
            l, r = 0, len(row)
            while l < r:
                mid = (l + r) >> 1
                if row[mid] == 1:
                    l = mid + 1
                else:
                    r = mid
            return l
        return sorted(range(len(mat)), key=lambda x: numOnes(mat[x]))[:k]