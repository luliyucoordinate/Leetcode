class Solution:
    def findLucky(self, arr: List[int]) -> int:
        return max([k for k, v in collections.Counter(arr).items() if k == v] + [-1])