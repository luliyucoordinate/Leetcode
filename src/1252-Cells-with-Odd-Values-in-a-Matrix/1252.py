class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        row, col, cntRow, cntCol = [False] * n, [False] * m, 0, 0
        for r, c in indices:
            row[r] ^= True
            col[c] ^= True
            cntRow += 1 if row[r] else -1 
            cntCol += 1 if col[c] else -1 
        return m * cntRow + n * cntCol - 2 * cntRow * cntCol