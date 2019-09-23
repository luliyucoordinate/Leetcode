class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        arr.sort()
        res, t = 0, 0
        for v in arr:
            t += v
            if t > 5000:
                break
            res += 1
        return res