from functools import lru_cache
class Solution:
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        sn, en = len(s1), len(evil)
        mod = 10**9 + 7
        
        ne = [0] * (en + 1)
        ne[0] = j = -1
        i = 0
        while i < en:
            while j != -1 and evil[i] != evil[j]: j = ne[j]
            i += 1
            j += 1
            ne[i] = j
            
        @lru_cache(None)
        def dfs(si=0, ei=0, lt=1, rt=1):
            if ei == en: return 0
            if si == sn: return 1
            
            l = s1[si] if lt else 'a'
            r = s2[si] if rt else 'z'
            res = 0
            for i in range(ord(l), ord(r) + 1):
                t = ei
                while t != -1 and evil[t] != chr(i):
                    t = ne[t]
                res += dfs(si + 1, t + 1, lt and (i == ord(l)), rt and (i == ord(r))) 
            return res % mod
        
        return dfs()