class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s_filter = ''.join(filter(str.isalnum, s)).lower()
        return s_filter[::-1] == s_filter

if __name__ == "__main__":
    s = "A man, a plan, a canal: Panama"
    print(Solution().isPalindrome(s))