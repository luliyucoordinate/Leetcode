func stringMatching(words []string) []string {
    root := &Trie{}
    
    for _, word := range words {
        for i := 0; i < len(word); i++ {
            root.Insert(word[i:len(word)])
        }
    }
    
    res := []string{}
    for _, word := range words {
        if root.Get(word) {
            res = append(res, word)
        }
    }
    return res
}

type Trie struct {
    val int
    next [26]*Trie
}

func (this *Trie) Insert(word string) {
    cur := this
    for i := 0; i < len(word); i++ {
        j := word[i] - 'a'
        if cur.next[j] == nil {
            cur.next[j] = &Trie{}
        }
        cur = cur.next[j]
        cur.val++
    }
}

func (this *Trie) Get(word string) bool {
    cur := this
    for i := 0; i < len(word); i++ {
        j := word[i] - 'a'
        if cur.next[j] == nil {
            return false
        }
        cur = cur.next[j]
    }
    return cur.val > 1
}