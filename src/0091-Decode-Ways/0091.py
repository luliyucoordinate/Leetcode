class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """ 
        if not s or s.startswith('0'):
            return 0

        if len(s) == 1 and s[0] != '0':
            return 1

        s_len = len(s)
        mem = [0 for _ in range(s_len + 1)]
        mem[0] = 1 if s[0] != '0' else 0
        mem[1] = 1 if s[1] != '0' else 0
        
        for i in range(2, s_len + 1):
            if 1 <= int(s[i - 1]) <= 9:
                mem[i] += mem[i - 1]
            if 10 <= int(s[i-2:i]) <= 26:
                mem[i] += mem[i - 2]

        return mem[-1]

if __name__ == '__main__':
    s = "12120"
    print(Solution().numDecodings(s))
