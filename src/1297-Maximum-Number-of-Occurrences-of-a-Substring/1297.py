class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        cnt = collections.Counter([s[i:i + minSize] for i in range(len(s) - minSize + 1)])
        for k, v in cnt.most_common():
            if len(set(k)) <= maxLetters:
                return v
        return 0