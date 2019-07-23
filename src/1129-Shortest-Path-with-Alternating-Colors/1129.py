class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        g0, g1 = collections.defaultdict(list), collections.defaultdict(list)
        for i, j in red_edges:
            g0[i].append(j)
        for i, j in blue_edges:
            g1[i].append(j)
        g = [g0, g1]
        
        res = [float("inf")] * n
        q = [(0, 0, 0), (0, 1, 0)]
        vis = {(0, 0), (0, 1)}
        while len(q):
            node, color, level = q.pop(0)
            res[node] = min(res[node], level)

            nc = not color
            for nd in g[nc][node]:
                if (nd, nc) not in vis:
                    q.append((nd, nc, level + 1))
                    vis.add((nd, nc))
        
        return [-1 if i == float("inf") else i for i in res]  