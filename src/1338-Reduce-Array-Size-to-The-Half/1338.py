class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        n, total, res = len(arr) // 2, 0, 0
        freq = collections.Counter(arr)
        cnt = collections.Counter(freq.values())
        
        for i in sorted(cnt.keys(), reverse=True):
            dif = n - total
            x = min(cnt[i], (dif + i - 1)//i)
            res += x
            total += x * i
            if total >= n:
                return res
        return res