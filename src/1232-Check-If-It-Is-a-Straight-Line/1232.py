class Solution:
    def checkStraightLine(self, c: List[List[int]]) -> bool:
        return all((x - c[0][0]) * (y - c[1][1]) == (x - c[1][0]) * (y - c[0][1]) for x, y in c[2:])