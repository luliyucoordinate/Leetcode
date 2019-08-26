class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        w = sorted([i.count(min(i)) for i in words])
        return [len(w) - bisect.bisect_right(w, i.count(min(i))) for i in queries]