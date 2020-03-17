class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        heap = []
        res = sSum = 0
        
        for e, s in sorted(zip(efficiency, speed), reverse=True):
            sSum += s
            res = max(res, sSum * e)
            heapq.heappush(heap, s)
            if len(heap) >= k: sSum -= heapq.heappop(heap)
        return res % (10**9 + 7)