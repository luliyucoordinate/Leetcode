class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        cnt, pre = [0] * 121, [0] * 121
        for a in ages:
            cnt[a] += 1

        for i in range(1, 121):
            pre[i] = pre[i-1] + cnt[i]
        
        res = 0
        for i in range(15, 121):
            res += (pre[i] - pre[i//2 + 7] - 1) * cnt[i]
        return res