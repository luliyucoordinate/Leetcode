var nodes map[*Trie]int

func minimumLengthEncoding(words []string) int {
    root := &Trie{next: make(map[byte]*Trie)}
    nodes = make(map[*Trie]int)

	for i, word := range words {
		root.Insert(word, i)
	}

	res := 0
	for node, i := range nodes {
		if len(node.next) == 0 {
			res += len(words[i]) + 1
		}
	}
	return res
}

type Trie struct {
	next map[byte]*Trie    
}

func (this *Trie) Insert(word string, id int)  {
    cur := this
    for i := len(word) - 1; i >= 0; i-- {
        c := word[i]
        if cur.next[c] == nil {
            cur.next[c] = &Trie{next: make(map[byte]*Trie)}
        }
        cur = cur.next[c]
    }
    nodes[cur] = id
}