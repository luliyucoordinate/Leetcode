class Node:
    def __init__(self, isWord=False):
        self.isWord = isWord
        self.next = dict()
        
class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        cur = self.root
        for c in word:
            if c not in cur.next:
                cur.next[c] = Node()
            cur = cur.next[c]
            
        if not cur.isWord:
            cur.isWord = True
        
    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        cur = self._search(word)
        return cur != None and cur.isWord
        
    def _search(self, word):
        cur = self.root
        for c in word:
            if c not in cur.next:
                return None
            cur = cur.next[c]
            
        return cur
        
    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        return self._search(prefix) != None 