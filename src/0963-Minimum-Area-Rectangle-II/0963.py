import itertools, collections
class Solution:
    def minAreaFreeRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        points = [complex(*point) for point in sorted(points)]
        mem = collections.defaultdict(list)
        for p, q in itertools.combinations(points, 2):
            mem[q - p].append((p + q) / 2)
            
        res = float('inf')
        for v1, mid_points in mem.items():
            for a, b in itertools.combinations(mid_points, 2):
                v2 = a - b
                if abs(v1.real * v2.real + v1.imag * v2.imag) < 1e-5:
                    res = min(res, abs(v1) * abs(v2))
                    
        return res if res != float('inf') else 0