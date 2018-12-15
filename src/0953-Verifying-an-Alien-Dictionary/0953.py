class Solution:
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        order = {c:i for i, c in enumerate(order)}
        
        for word1, word2 in zip(words, words[1:]):
            for a,b in zip(word1, word2):
                if a != b:
                    if order[a] > order[b]:
                        return False
                    break
            else:
                if len(word1) > len(word2):
                    return False
        return True