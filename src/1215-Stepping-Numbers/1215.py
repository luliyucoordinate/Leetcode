class Solution:
    def countSteppingNumbers(self, l: int, r: int) -> List[int]:
        res = []
        def bfs(s):
            q = [s]
            while len(q):
                pre = q.pop(0)
                if pre <= r and pre >= l:
                    res.append(pre)
                if pre == 0 or pre > r:
                    return   

                lt = pre % 10
                s1, s2 = pre * 10 + lt - 1, pre*10 + lt + 1
                if lt == 0:
                    q.append(s2)
                elif lt == 9:
                    q.append(s1)
                else:
                    q.append(s1)
                    q.append(s2)
                
        for i in range(10):
            bfs(i)
        return sorted(res)