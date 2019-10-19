class Solution:
    def sumSubseqWidths(self, A: List[int]) -> int:
        return sum(((1 << i) - (1 << len(A) - i - 1)) * a for i, a in enumerate(sorted(A))) % (10**9 + 7)