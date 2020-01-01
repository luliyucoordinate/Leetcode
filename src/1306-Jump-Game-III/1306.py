class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        q = [start]
        vis = [False] * len(arr)
        vis[start] = True
        
        while q:
            cur = q.pop(0)
            if arr[cur] == 0:
                return True
            
            vis[cur] = True
            for i in [cur + arr[cur], cur - arr[cur]]:
                if 0 <= i < len(arr) and not vis[i]:
                    q.append(i)
        return False