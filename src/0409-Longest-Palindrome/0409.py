class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = collections.Counter(s)
        res = sum(i // 2 * 2 for i in cnt.values())
        return res + 1 if res < len(s) else res