class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        wordDict = set(wordDict)
        mem = dict()
        return self._wordBreak(s, wordDict, mem)
        
    def _wordBreak(self, s, wordDict, mem):
        if s in mem:
            return mem[s]
        
        res = list()
        if not s:
            res.append("")
            return res
        
        for i in range(len(s)+1):
            if s[:i] in wordDict:
                sublist = self._wordBreak(s[i:], wordDict, mem)
                for it in sublist:
                    res.append(str(s[:i]) + ('' if not it else ' ') + it)
                
        mem[s] = res
        return res            

if __name__ == "__main__":
    s = "catsanddog"
    wordDict = ["cat","cats","and","sand","dog"] 
    print(Solution().wordBreak(s, wordDict))