class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ''
        res = ''
        min_val = min(strs)
        min_val, strs[0] = strs[0], min_val
        print(min_val)
        for i, c in enumerate(strs[0]):
            if not all([s[i] == c for s in strs[1:]]):
                break
            res += c
                
        return res
        