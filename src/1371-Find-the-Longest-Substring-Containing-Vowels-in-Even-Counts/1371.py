class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        vis = {0: -1}
        vowels = collections.defaultdict(int)
        for i, c in enumerate("aeiou"): vowels[c] = 1 << (i + 1) >> 1
            
        res = cur = 0
        for i, c in enumerate(s):
            cur ^= vowels[c]
            vis.setdefault(cur, i)
            res = max(res, i - vis[cur])
        return res