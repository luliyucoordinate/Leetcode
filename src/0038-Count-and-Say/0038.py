class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        
        def count(st):
            res, c = "", 1
            for i in range(1, len(st)):
                if st[i] != st[i-1]:
                    res += str(c) + st[i-1]
                    c = 0
                c += 1
                
            return res + str(c) + st[-1]
        
        res = "1"
        for _ in range(1, n):
            res = count(res)
        return res   