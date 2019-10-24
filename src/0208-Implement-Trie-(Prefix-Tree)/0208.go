type Trie struct {
    next map[rune]*Trie
    isWord bool
}


/** Initialize your data structure here. */
func Constructor() Trie {
    return Trie{next: make(map[rune]*Trie)}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
    cur := this
    for _, c := range word {
        if cur.next[c] == nil {
            cur.next[c] = &Trie{next: make(map[rune]*Trie)}
        }
        cur = cur.next[c]
    }
    if !cur.isWord {
        cur.isWord = true
    }
}


func (this *Trie) search(word string) *Trie {
    cur := this
    for _, c := range word {
        if cur.next[c] == nil {
            return nil
        }
        cur = cur.next[c]
    }
    return cur
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
    cur := this.search(word)
    if cur != nil && cur.isWord {
        return true
    }
    return false
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
    if this.search(prefix) != nil {
        return true
    }
    return false
}