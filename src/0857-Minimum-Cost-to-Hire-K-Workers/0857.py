class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        workers = sorted([[w/ q, q] for w, q in zip(wage, quality)])
        res, qsum = float('inf'), 0
        heap = []

        for r, q in workers:
            qsum += q
            if len(heap) == K - 1: res = min(res, qsum * r)
            heapq.heappush(heap, -q)
            if len(heap) >= K: qsum += heapq.heappop(heap)
        return res