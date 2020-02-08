class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s, n = sum(nums), len(nums)
        if s %2 :
            return False
        
        t = s//2
        nums.sort(reverse=True)
        vis = [0] * n
        
        def dfs(cur, u, p):
            if u == 2: return True
            if cur == t: return dfs(0, u + 1, 0)
            
            i = p
            while i < n:
                if vis[i] or (cur + nums[i] > t): 
                    i += 1
                    continue
                    
                vis[i] = 1
                if dfs(cur + nums[i], u, i + 1): return True
                vis[i] = 0
                
                if not cur or cur + nums[i] == t: return False 
                
                j = i
                while j < n and nums[i] == nums[j]: j += 1 
                i = j - 1
                i += 1
            return False
        
        return dfs(0, 0, 0)