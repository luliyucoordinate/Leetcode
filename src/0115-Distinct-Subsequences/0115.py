class Solution:
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        t_len = len(t)
        mem = [0]*(t_len+1)
        mem[0] = 1
        for s_c in s:
            for i in range(t_len-1, -1, -1):
                if t[i] == s_c:
                    mem[i+1] += mem[i]

        return mem[-1]
        
if __name__ == "__main__":
    s = "rabbbit"
    t = "rabbit"
    print(Solution().numDistinct(s, t))