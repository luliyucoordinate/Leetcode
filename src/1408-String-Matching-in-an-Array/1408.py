class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        def add(word):
            node = root
            for c in word:
                node = node[c]
                node['#'] = node.get('#', 0) + 1

        def get(word):
            node = root
            for c in word:
                if (node := node.get(c)) is None: return False
            return node['#'] > 1

        Trie = lambda: collections.defaultdict(Trie)
        root = Trie()
        for word in words:
            for i in range(len(word)):
                add(word[i:])
        return [word for word in words if get(word)]