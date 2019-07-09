class Solution:
    def hIndex(self, citations: List[int]) -> int:
        l, n, r = 0, len(citations), len(citations)-1
        while l < r:
            mid = (l + r + 1) >> 1
            if citations[mid] <= n - mid:
                l = mid
            else:
                r = mid - 1
        if l < n and n - l > citations[l]:
            return n - l - 1
        return n - l