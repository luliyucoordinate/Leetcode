class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        A = [0]
        for a in arr:
            A.append(A[-1] ^ a)
        return [A[l] ^ A[r + 1] for l, r in queries]