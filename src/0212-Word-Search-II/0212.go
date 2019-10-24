type Trie struct {
    next map[rune]*Trie
    wordId int
}

func findWords(board [][]byte, words []string) []string {
    r, c := len(board), len(board[0])
    dire := [4][2]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}
    root := &Trie{next:make(map[rune]*Trie), wordId:-1}
    for i, v := range words {
        node := root
        for _, ch := range v {
            if node.next[ch] == nil {
                node.next[ch] = &Trie{next:make(map[rune]*Trie), wordId:-1}
            }
            node = node.next[ch]
        }
        node.wordId = i
    }
    
    res := make([]string, 0)
    var dfs func(i, j int, node *Trie) 
    dfs = func(i, j int, node *Trie) {
        if i < 0 || i >= r || j < 0 || j >= c || node.next[rune(board[i][j])] == nil {
            return
        }
        
        tmp := board[i][j] 
        board[i][j], node = '$', node.next[rune(tmp)]
        if node.wordId != -1 {
            res = append(res, words[node.wordId])
            node.wordId = -1
        }
        
        for _, it := range dire {
            nx, ny := it[0] + i, it[1] + j
            dfs(nx, ny, node)
        }
        board[i][j] = tmp
    }
    
    for i := 0; i < r; i++ {
        for j := 0; j < c; j++ {
            dfs(i, j, root)
        }
    }
    return res
}