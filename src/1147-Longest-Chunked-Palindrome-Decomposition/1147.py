class Solution:
    def longestDecomposition(self, text: str) -> int:
        n = len(text)
        for i in range(1, n//2 + 1):
            if text[:i] == text[n-i:]:
                return 2 + self.longestDecomposition(text[i:n-i])
        return 0 if n == 0 else 1 