class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        s_dict = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        res, pre = 0, 0
        for i in s:
            cur = s_dict[i]
            if pre < cur:
                res += (cur - 2*pre)
            else:
                res += cur
            pre = cur
        return res