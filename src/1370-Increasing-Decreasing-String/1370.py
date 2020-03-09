class Solution:
    def sortString(self, s: str) -> str:
        cnt, res  = collections.Counter(s), []
        st = sorted(cnt.keys())
        
        while len(res) < len(s):   
            for c in st:
                if cnt[c]:
                    res.append(c)
                    cnt[c] -= 1
                    
            for c in st[::-1]:
                if cnt[c]:
                    res.append(c)
                    cnt[c] -= 1
        return ''.join(res)