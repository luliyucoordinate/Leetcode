class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        g = collections.defaultdict(list)
        for i, j, w in edges:
            g[i].append((j, w))
            g[j].append((i, w))
            
        def dijkstra(node):
            dist = [float("inf")] * n
            dist[node] = 0
            hp = [(0, node)]
            
            while hp:
                d, cur = heapq.heappop(hp)
                if dist[cur] < d:
                    continue
                
                if d > distanceThreshold:
                    break
                
                for ne, w in g[cur]:
                    if d + w < dist[ne]:
                        dist[ne] = d + w
                        heapq.heappush(hp, (dist[ne], ne))
            return sum(d <= distanceThreshold for d in dist)
            
        res = (0, float("inf"))
        for i in range(n):
            t = dijkstra(i)
            if t <= res[1]:
                res = (i, t)
        return res[0]