class Solution:
    def maxRepOpt1(self, s: str) -> int:
        res, n, l, mf, mc = 0, len(s), 0, 0, s[0]
        d = collections.defaultdict(int)
        for r, c in enumerate(s):
            d[c] += 1
            if d[c] > mf:
                mf, mc = d[c], c
                
            if r - l + 1 - mf > 1:
                d[s[l]] -= 1
                l += 1
            res = max(res, r - l + 1)
        return min(res, collections.Counter(s)[mc])