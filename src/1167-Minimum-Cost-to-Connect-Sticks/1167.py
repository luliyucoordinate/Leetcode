import heapq
class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        heapq.heapify(sticks)
        res = 0
        while len(sticks) > 1:
            a, b = heapq.heappop(sticks), heapq.heappop(sticks)
            res += a + b
            heapq.heappush(sticks, a + b)
        return res