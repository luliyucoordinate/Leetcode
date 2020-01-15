class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (2 * s)[1:-1]