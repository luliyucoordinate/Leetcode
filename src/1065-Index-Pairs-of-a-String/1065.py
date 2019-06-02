class Solution:
    def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
        res, n = list(), len(text)
        for i in range(n):
            for word in words:
                if n - i >= len(word) and word == text[i:i + len(word)]:
                    res.append([i, i + len(word) - 1])
        
        res.sort()
        return res