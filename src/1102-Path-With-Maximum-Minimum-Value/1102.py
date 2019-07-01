import heapq
class Solution:
    def maximumMinimumPath(self, A: List[List[int]]) -> int:
        dire = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        r, c = len(A), len(A[0])
        vi = {(0, 0)}
        q = [[-A[0][0], 0, 0]]
        heapq.heapify(q)
        
        while q:
            pre, x, y = heapq.heappop(q)
            if x == r-1 and y == c-1:
                return -pre
            
            for i, j in dire:
                nx, ny = i + x, j + y
                if nx >= 0 and nx < r and ny >= 0 and ny < c and (nx, ny) not in vi:
                    vi.add((nx, ny))
                    heapq.heappush(q, [max(pre, -A[nx][ny]), nx, ny])

        return 0