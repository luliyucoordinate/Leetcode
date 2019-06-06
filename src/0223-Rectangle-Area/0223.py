class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        x = min(C, G) - max(A, E)
        y = min(D, H) - max(B, F)
        return (C - A) * (D - B) + (G - E) * (H - F) - max(x, 0)*max(y, 0)