class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        res = [255, 0, 0, 0, 0]
        sum_all = sum(count)
        l, r = sum_all//2, sum_all//2
        if not (sum_all & 1):
            r += 1
            
        pre, lc = 0, 0
        for i, val in enumerate(count):
            if val:
                res[0] = min(res[0], i)
                res[1] = i
            res[2] += i * val/sum_all
            
            if pre < l and pre + val >= l:
                res[3] += i/2
            if pre < r and pre + val >= r:
                res[3] += i/2
            pre += val
            
            if val > lc:
                lc = val
                res[4] = i
        return [float(i) for i in res]