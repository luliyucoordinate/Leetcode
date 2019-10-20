class Solution:
    def maximizeSweetness(self, sweetness: List[int], K: int) -> int:
        l, r = 1, sum(sweetness) // (K + 1)
        while l < r:
            mid = (l + r + 1) >> 1
            cur = cuts = 0
            for sw in sweetness:
                cur += sw
                if cur >= mid:
                    cuts += 1
                    cur = 0
            if cuts > K:
                l = mid
            else:
                r = mid - 1
        return l