class Solution:
        
    def maxPoints(self, points: List[List[int]]) -> int:
        def GCD(a, b):
            return a if b == 0 else GCD(b, a % b)

        res, n = 1, len(points)
        lines = defaultdict(int)
        for i in range(n):
            lines.clear()
            for j in range(i + 1, n):
                p1, p2 = points[i], points[j]
                a, b = p1[0] - p2[0], p1[1] - p2[1]
                c = GCD(a, b)
                a //= c
                b //= c
                lines[a * 20000 + b] += 1
            for _, v in lines.items():
                res = max(res, v + 1)
        return res
