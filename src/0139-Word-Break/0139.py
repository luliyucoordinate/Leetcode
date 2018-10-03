class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        return self._wordBreak(s, set(wordDict), 0, set())
        
    def _wordBreak(self, s, words, start, mem):
        if start == len(s):
            return True
        
        if start in mem:
            return False

        for i in range(start + 1, len(s) + 1):
            if i in mem:
                continue

            sub = s[start:i]
            if sub in words and self._wordBreak(s, words, i, mem):
                return True

        mem.add(start)
        return False

if __name__ == '__main__':
    s = "applepenapple"
    wordDict = ["apple", "pen"]
    print(Solution().wordBreak(s, wordDict))