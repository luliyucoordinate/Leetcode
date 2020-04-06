class Solution:
    def checkOverlap(self, r: int, xc: int, yc: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        x, y = (x1 + x2) / 2, (y1 + y2) / 2
        h = [x2 - x, y2 - y]
        v = [abs(x - xc), abs(y - yc)]
        u = [max(v[0] - h[0], 0), max(v[1] - h[1], 0)]
        return r**2 >= (u[0]**2 + u[1]**2)