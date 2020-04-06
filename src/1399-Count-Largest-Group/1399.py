class Solution:
    def countLargestGroup(self, n: int) -> int:
        cnt, mx, res = collections.defaultdict(int), 0, 0
        for i in range(1, n + 1):
            t = sum([int(j) for j in str(i)])
            cnt[t] += 1
            mx = max(mx, cnt[t])
        
        return sum([i == mx for i in cnt.values()])