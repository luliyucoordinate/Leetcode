import string
class Solution:
    m = {c: [i // 5, i % 5] for i, c in enumerate(string.ascii_lowercase)}
    def alphabetBoardPath(self, target: str) -> str:
        x0, y0 = 0, 0
        res = ""
        for c in target:
            x, y = self.m[c]
            res += 'L'*max(0, y0 - y) + 'U'*max(0, x0 - x) + 'D'*max(0, x - x0) + 'R'*max(0, y - y0) + '!'
            x0, y0 = x, y
        return res