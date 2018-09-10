class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        from collections import Counter
        s_len, t_len = len(s), len(t)
        count = t_len
        tChar = Counter(t)
        l = 0
        r = 0
        minLength = s_len + t_len + 1
        result = str()
        while l < s_len:   
            if r < s_len:
                print(l, r, count)
                if tChar[s[r]] >= 1:
                    count -= 1
                tChar[s[r]] -= 1
                r += 1
                if count == 0:
                    if r - l < minLength:
                        minLength = r - l
                        result = s[l:r]
            else:
                print(l, r, count)
                if tChar[s[l]] >= 0:
                    count += 1
                tChar[s[l]] += 1
                l += 1
                if count == 0:
                    if r - l < minLength:
                        minLength = r - l
                        result = s[l:r]
        return result
        
if __name__ == "__main__":
    s = "abc"
    p = "b"
    print(Solution().minWindow(s, p))