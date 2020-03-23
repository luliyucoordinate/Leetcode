class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        def cal(x):
            res = 0
            while x != 1:
                if x & 1: x = x * 3 + 1
                else: x //= 2
                res += 1
            return res
            
        return sorted(list(range(lo, hi + 1)), key=lambda x: cal(x))[k - 1]