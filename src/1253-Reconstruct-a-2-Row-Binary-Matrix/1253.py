class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        n = len(colsum)
        res = [[0] * n for _ in range(2)]
        for i in range(n):
            res[0][i] = int(colsum[i] == 2 or (colsum[i] == 1 and lower < upper))
            res[1][i] = int(colsum[i] == 2 or (colsum[i] == 1 and not res[0][i]))
            upper -= res[0][i]
            lower -= res[1][i]
        return res if lower == 0 and upper == 0 else []