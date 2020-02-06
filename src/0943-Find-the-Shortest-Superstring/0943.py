class Solution:
    def shortestSuperstring(self, A: List[str]) -> str:
        n = len(A)
        g = [[0] * n for _ in range(n)]
        path = [[0] * n for _ in range(1 << n)]
        vis = (1 << n) - 1
        
        def dis(a, b):
            for i in range(len(a)):
                if len(a) - i <= len(b) and a[i:] == b[:len(a) - i]:
                    return len(b) - len(a) + i
            return len(b)
        
        for i in range(n):
            for j in range(n):
                if i == j: continue
                g[i][j] = dis(A[i], A[j]) #计算字符串距离
        
        dp = [[float("inf")] * n for _ in range(1 << n)]
        best, pos = float("inf"), -1 #记录最优解的位置
        
        # TSP
        for i in range(1 << n):
            for j in range(n):
                if ((i >> j) & 1) == 0: continue
                pre = i - (1 << j)
                if pre == 0: # j作为第一个位置开始
                    dp[i][j] = len(A[j]) 
                else:
                    for k in range(n):
                        if ((pre >> k) & 1) == 0: continue
                        p = dp[pre][k] + g[k][j] # 如果pre>k + k->j < pre->j，进行放缩
                        if dp[i][j] > p:
                            dp[i][j], path[i][j] = p, k # path记录j之前的位置k

                if i == vis and best > dp[i][j]: # 寻找最优解
                    best, pos = dp[i][j], j
      
        res, t = A[pos], vis
        while 1:
            pre = path[t][pos] # 依次弹出pos的前一个位置
            t -= (1 << pos)
            if t == 0: break
            res = A[pre] + res[len(A[pos])-g[pre][pos]:]
            pos = pre
            
        return res