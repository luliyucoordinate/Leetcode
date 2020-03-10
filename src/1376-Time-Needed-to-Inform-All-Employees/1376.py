class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        son = collections.defaultdict(list)
        for i, v in enumerate(manager):
            if v == -1: continue
            son[v].append(i)
            
        def dfs(x):
            return max(dfs(t) for t in son[x]) + informTime[x]
            
        return dfs(headID)