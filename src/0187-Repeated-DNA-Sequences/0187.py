class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res, mem = set(), set()
        for i in range(len(s)-9):
            cur = s[i:i+10]
            if cur in mem:
                res.add(cur)
            else:
                mem.add(cur)
                
        return list(res)