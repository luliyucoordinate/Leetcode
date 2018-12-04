class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 0:
            return list()
        if n == 1:
            return ["()"]
        res = set()
        tmp = self.generateParenthesis(n-1)
        for s in tmp:
            for i in range(len(s)):
                tmp = s[:i] + "()" + s[i:]
                res.add(tmp)
                
        return list(res)