var stringMatching = function(words) {
    let root = new Trie();
    for (let word of words) {
        for (let i = 0; i < word.length; i++) {
            root.insert(word.substring(i));
        }
    }
    
    let res = [];
    for (let word of words) {
        if (root.get(word)) res.push(word);
    }
    return res;
};

var Trie = function() {
    this.val = 0;
    this.next = {};
};

Trie.prototype.insert = function(word) {
    let cur = this;
    for (let c of word) {
        if (!cur.next[c]) {
            cur.next[c] = new Trie();
        }
        cur = cur.next[c];
        cur.val++;
    }
};

Trie.prototype.get = function(word) {
    let cur = this;
    for (let c of word) {
        if (!cur.next[c]) return false;
        cur = cur.next[c];
    }
    return cur.val > 1;
}