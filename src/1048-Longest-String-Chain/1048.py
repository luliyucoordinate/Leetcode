class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=len)
        mem = collections.defaultdict(int)
        for w in words:
            mem[w] = max(mem[w[:i] + w[i + 1:]] + 1 for i in range(len(w)))
        return max(mem.values())