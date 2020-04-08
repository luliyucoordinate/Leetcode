class Solution:
    def numSteps(self, s: str) -> int:
        res, add, n = 0, 0, len(s)
        for i in range(n - 1, 0, -1):
            res += 1
            if (1 if s[i] == '1' else 0) + add == 1: # 当前为奇数，需要加1和移位
                add = 1
                res += 1
        return res + add