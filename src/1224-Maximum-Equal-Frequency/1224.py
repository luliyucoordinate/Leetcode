class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        f, n = collections.defaultdict(int), len(nums)
        k, res = [0] * (n + 1), 0
        for i in range(1, n+1):
            a = nums[i-1]
            k[f[a]] -= 1
            f[a] += 1
            k[f[a]] += 1
            t = f[a]
            if k[t] * t == i and i < n:
                res = i + 1
            else:
                d = i - k[t] * t
                if d in [t + 1, 1] and k[d] == 1:
                    res = i
        return res