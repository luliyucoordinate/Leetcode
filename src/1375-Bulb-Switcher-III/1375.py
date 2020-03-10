class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        res, maxv = 0, 0
        for i, v in enumerate(light):
            maxv = max(v, maxv)
            if maxv == i + 1: res += 1
        return res