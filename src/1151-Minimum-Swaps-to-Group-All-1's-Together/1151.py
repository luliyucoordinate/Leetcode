class Solution:
    def minSwaps(self, data: List[int]) -> int:
        n, m = len(data), sum(data)
        cur, res = sum(data[:m]), n
        
        for i in range(m, n):
            res = min(res, m - cur)
            if data[i] == 1:
                cur += 1
            if data[i - m] == 1:
                cur -= 1
        return res