class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        step = 1
        wordDict = set(wordList)
        if endWord not in wordDict:
            return 0

        s1, s2 = set([beginWord]), set([endWord])
        while s1:
            stack = set([])
            for s in s1:
                if s in wordDict:
                    wordDict.remove(s)

            for s in s1:
                for i in range(len(beginWord)):
                    for j in 'abcdefghijklmnopqrstuvwxyz':
                        tmp = s[:i] + j + s[i+1:]
                        if tmp not in wordDict:
                            continue
                        if tmp in s2:
                            step += 1
                            return step
                        stack.add(tmp)

            if len(stack) < len(s2):
                s1 = stack
            else:
                s1, s2 = s2, stack

            step += 1

        return 0 

if __name__ == "__main__":
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]
    print(Solution().ladderLength(beginWord, endWord, wordList))
        