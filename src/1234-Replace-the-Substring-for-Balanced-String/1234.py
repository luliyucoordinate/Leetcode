class Solution:
    def balancedString(self, s: str) -> int:
        cnt = collections.Counter(s)
        res = n = len(s)
        i, avg = 0, n//4
        for j, c in enumerate(s):
            cnt[c] -= 1
            while i < n and all(avg >= cnt[x] for x in 'QWER'):
                res = min(res, j - i + 1)
                cnt[s[i]] += 1
                i += 1
        return res