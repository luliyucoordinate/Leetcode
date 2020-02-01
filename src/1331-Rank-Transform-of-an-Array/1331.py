class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        return map({a: i + 1 for i, a in enumerate(sorted(set(arr)))}.get, arr)