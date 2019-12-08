class Solution:
    def smallestDivisor(self, A: List[int], t: int) -> int:
        l, r = 1, 10**6
        while l < r:
            m = l + r >> 1
            if sum((i + m - 1) // m for i in A) > t:
                l = m + 1
            else:
                r = m
        return l