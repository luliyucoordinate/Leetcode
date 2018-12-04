class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        haystack_len, needle_len = len(haystack), len(needle)
        if haystack_len < needle_len:
            return -1
        
        for i in range(haystack_len - needle_len + 1):
            if haystack[i:i+needle_len] == needle:
                return i
        return -1