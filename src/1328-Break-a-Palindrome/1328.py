class Solution:
    def breakPalindrome(self, p: str) -> str:
        for i in range(len(p) // 2):
            if p[i] != 'a':
                return p[:i] + 'a' + p[i + 1:]
        return p[:-1] + 'b' if p[:-1] else ''