class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        d = dict()
        for i, v in enumerate(keyboard):
            d[v] = i
        
        res, pre = 0, 0
        for c in word:
            res += abs(d[c] - pre)
            pre = d[c]
        return res