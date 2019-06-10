from collections import defaultdict
class Solution:
    def smallestSubsequence(self, text: str) -> str:
        cnt, used = defaultdict(int), defaultdict(int)
        for c in text:
            cnt[c] += 1
        
        res = list()
        for c in text:
            cnt[c] -= 1
            if used[c] == 1:
                continue
            while res and res[-1] > c and cnt[res[-1]]:
                used[res[-1]] = 0
                res.pop()
            res.append(c)
            used[c] = 1
        return "".join(res)