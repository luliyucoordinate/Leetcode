class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        res, usedChar, low = 0, {}, -1
        for i, v in enumerate(S):
            if v in usedChar and usedChar[v] >= low:
                low = usedChar[v]
            if i - low >= K:
                res += 1
            usedChar[v] = i
        return res