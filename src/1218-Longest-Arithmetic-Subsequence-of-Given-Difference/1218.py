class Solution:
    def longestSubsequence(self, arr: List[int], dif: int) -> int:
        mem, res = {}, 1
        for i in arr:
            if i - dif in mem:
                mem[i] = mem[i-dif] + 1
            else:
                mem[i] = 1
            res = max(res, mem[i])
        return res