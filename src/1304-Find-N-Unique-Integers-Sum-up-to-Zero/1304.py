class Solution:
    def sumZero(self, n: int) -> List[int]:
        return list(range(1 - n, n, 2))