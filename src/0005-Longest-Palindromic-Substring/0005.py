class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) < 2 or s == s[::-1]:
            return s
        
        start, maxlength = 0, 1
        for i in range(len(s)):
            odd = s[i-maxlength-1:i+1]
            even = s[i-maxlength:i+1]    
            if i-maxlength-1 >= 0 and odd == odd[::-1]:
                start = i-maxlength-1
                maxlength += 2
            elif i-maxlength >= 0 and even == even[::-1]:
                start = i-maxlength
                maxlength += 1
        return s[start:start+maxlength]


if __name__ == "__main__":
    s = "babad"
    print(Solution().longestPalindrome(s))