class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        area = sorted((i - r, i + r) for i, r in enumerate(ranges) if r > 0)
        left = right = count = i = 0
        while i < len(area):
            if area[i][0] > left:
                return -1
            right = max(right, area[i][1])
            count += 1
            while i < len(area) and area[i][0] <= left:
                right = max(right, area[i][1])
                i += 1
            if right >= n:
                return count
            left = right
        return -1