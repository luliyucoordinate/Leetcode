import heapq
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        points = [(L, -H, R) for L, R, H in buildings] + [(R, 0, 0) for R in set(r for _, r, _ in buildings)]
        points.sort()
        heap, res = [(0, float('inf'))], [[0, 0]]
        for l, nh, r in points:
            while heap[0][1] <= l:
                heapq.heappop(heap)
            if nh:
                heapq.heappush(heap, (nh, r))
            if res[-1][1] != -heap[0][0]:
                res += [[l, -heap[0][0]]]
        return res[1:]