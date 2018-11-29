class Solution:
    def bagOfTokensScore(self, tokens, p):
        """
        :type tokens: List[int]
        :type P: int
        :rtype: int
        """
        result, cur = 0, 0
        tokens.sort()
        while tokens and cur >= 0:
            if tokens[0] <= p:
                p -= tokens.pop(0)
                cur += 1
                if result < cur:
                    result = cur
                    
                print(result)
            else:
                p += tokens.pop()
                cur -= 1
                
        return result
                