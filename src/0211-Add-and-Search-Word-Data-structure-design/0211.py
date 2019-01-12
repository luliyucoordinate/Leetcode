import collections
class WordDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = collections.defaultdict(list)    

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        self.root[len(word)].append(word)

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        if not word:
            return False
        
        if "." not in word:
            return word in self.root[len(word)]
        
        for v in self.root[len(word)]:
            for i, s in enumerate(word):
                if s != v[i] and s != ".":
                    break
            else:
                return True
        return False