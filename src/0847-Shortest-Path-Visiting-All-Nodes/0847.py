class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        mem, final, q, res = set(), (1 << len(graph)) - 1, [(i, 1 << i) for i in range(len(graph))], 0
        while True:
            n = len(q)
            for _ in range(n):
                node, state = q.pop(0)
                if state == final:
                    return res
                for j in graph[node]:
                    new_stat = (j, state | 1 << j)
                    if new_stat not in mem:
                        q.append(new_stat)
                        mem.add(new_stat)
            res += 1