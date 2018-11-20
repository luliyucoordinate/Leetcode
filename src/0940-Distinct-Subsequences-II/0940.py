class Solution:
    def distinctSubseqII(self, S):
        """
        :type S: str
        :rtype: int
        """
        mem, cur_sum = {}, 1
        for s in S:
            old_sum = cur_sum
            cur_sum *= 2
            if s in mem:
                cur_sum -= mem[s]         
            mem[s] = old_sum
        return (cur_sum -1) % (pow(10,9)+7)

if __name__ == "__main__":
    S = "aba"
    print(Solution().distinctSubseqII(S))