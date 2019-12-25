class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k != 0:
            return False
        
        cnt = collections.Counter(nums)
        keys = sorted(cnt)
        for n in keys:
            t = cnt[n]
            if t:
                for i in range(n, n + k):
                    if cnt[i] < t:
                        return False
                    cnt[i] -= t
        return True