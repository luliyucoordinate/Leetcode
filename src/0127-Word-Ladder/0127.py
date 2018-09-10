class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordList.append(endWord)
        q = list()
        q.append([beginWord, 0])
        if beginWord in wordList:
            wordList.remove(beginWord)

        while any(q):
            tmpStr, step = q.pop(0)
            
            if tmpStr == endWord:
                return step

            for i in range(len(tmpStr)):
                _tmpStr = tmpStr
                for i in range(26):
                    _tmpStr[i] = str(chr(97 + i))
                    if wordList.count(_tmpStr) == 1:
                        q.append([_tmpStr, step + 1])
                        wordList.remove(_tmpStr)

        

if __name__ == '__main__':
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]
    print(Solution().ladderLength(beginWord, endWord, wordList))
        