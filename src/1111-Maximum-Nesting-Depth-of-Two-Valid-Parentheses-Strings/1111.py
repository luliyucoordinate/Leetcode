class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        return [i & 1 ^ (seq[i] == ')') for i, c in enumerate(seq)]