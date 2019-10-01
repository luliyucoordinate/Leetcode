class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        all_sum = sum(stones)
        mem = [0]*(all_sum//2+1)
        mem[0] = 1
        for i in stones:
            for j in range(all_sum//2, i-1, -1):
                mem[j] |= mem[j - i]

        for i in range(all_sum//2, -1, -1):
            if mem[i]:
                return all_sum - 2*i
        return 0