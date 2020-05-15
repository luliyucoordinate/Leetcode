class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        res = cur = 0
        cnt = {0: [1, -1]}
        for k, a in enumerate(arr):
            cur ^= a
            if cur not in cnt:
                cnt[cur] = [0, 0]
            n, total = cnt[cur]
            res += (k - 1) * n - total
            cnt[cur] = [n + 1, total + k]
        return res