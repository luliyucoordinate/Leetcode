class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        direct = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        r, c, res = len(board), len(board[0]), []
        
        root = {}
        for word in words:
            node = root
            for i in word:
                if i not in node:
                    node[i] = {}
                node = node[i]
            node['#'] = word
        
        def dfs(i, j, node):
            if i < 0 or i >= r or j < 0 or j >= c\
                or board[i][j] not in node:
                return
            
            tmp, board[i][j] = board[i][j], '$'
            trie = node[tmp]
            if '#' in trie:
                res.append(trie.pop('#'))
            
            for x, y in direct:
                nx, ny = x + i, y + j
                dfs(nx, ny, trie)
            board[i][j] = tmp
            if not trie:
                node.pop(tmp)
   
        for i in range(r):
            for j in range(c):  
                dfs(i, j, root)
        return res