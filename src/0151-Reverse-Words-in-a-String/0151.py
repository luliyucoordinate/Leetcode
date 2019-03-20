class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join([i for i in s.split()][::-1])