class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        l, s, res = -1, 0, 0
        for r, v in enumerate(arr):
            s += v
            if r - l == k:
                if s >= k * threshold:
                    res += 1
                l += 1   
                s -= arr[l]
        return res