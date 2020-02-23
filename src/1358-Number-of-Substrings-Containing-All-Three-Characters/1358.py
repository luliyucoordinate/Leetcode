class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        res, l, cnt = 0, -1, {c : 0 for c in 'abc'}
        
        for r, c in enumerate(s):
            cnt[c] += 1
            while all(cnt.values()):
                res += len(s) - r
                l += 1
                cnt[s[l]] -= 1
        return res