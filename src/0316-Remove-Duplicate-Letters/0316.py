from collections import defaultdict
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        cnt, used = defaultdict(int), defaultdict(int)
        for c in s:
            cnt[c] += 1
            
        res = list()
        for c in s:
            cnt[c] -= 1
            if used[c]:
                continue
            while res and res[-1] > c and cnt[res[-1]]:
                used[res[-1]] = 0
                res.pop()
            res.append(c)
            used[c] = 1
        return "".join(res)