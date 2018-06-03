class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        s_len = len(s)
        t_len = len(t)
        if s_len < t_len:
            return ""
        
        tChar = [0]*256
        for i in t:
            tChar[ord(i)] += 1

        l = 0
        r = 0
        minR = 0
        minL = 0
        minLength = s_len + 1
        while l < s_len:
            if r < s_len:
                if tChar[s[r]] >= 1:
                    tChar[s[r]] -= 1
                    r += 1
                else:
            
            if r - l < minLength:
                minLength = r - l
                minR = r
                minL = l
            l += 1

        return s[minL:minR]
        
if __name__ == "__main__":
    s = "ADOBECODEBANC"
    p = "ABC"
    print(Solution().minWindow(s, p))