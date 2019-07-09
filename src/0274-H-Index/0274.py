class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        cnt = [0] * (n + 1)
        for c in citations:
            cnt[min(n, c)] += 1
        
        i, total = n, cnt[-1]
        while total < i:
            i -= 1
            total += cnt[i]
        return i