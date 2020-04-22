class Solution:
    def minNumberOfFrogs(self, cr: str) -> int:
        res, frogs = 0, 0
        st = [0] * 5
        for i in cr:
            if i == 'c':
                st[0] += 1
                frogs += 1
            elif i == 'r':
                st[1] += 1
            elif i == 'o':
                st[2] += 1
            elif i == 'a':
                st[3] += 1
            else:
                st[4] += 1
                frogs -= 1
            res = max(res, frogs)
            if not (st[0] >= st[1] >= st[2] >= st[3] >= st[4]): return -1
        
        if st[0] == st[1] == st[2] == st[3] == st[4]:
            return res
        return -1