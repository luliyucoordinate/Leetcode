var Node = function() {
    this.next = new Map();
}

var Trie = function() {
    this.root = new Node();
    this.nodes = new Map();
};

Trie.prototype.insert = function(word, id) {
    let cur = this.root;
    for (let i = word.length - 1; ~i; i--) {
        let c = word[i];
        if (!cur.next.get(c)) {
            cur.next.set(c, new Node());
        }
        cur = cur.next.get(c);
    }
    this.nodes.set(cur, id);
};

var minimumLengthEncoding = function(words) {
    let root = new Trie();
    for (let i = 0; i < words.length; i++) {
        root.insert(words[i], i);
    }

    let res = 0;
    for (let [k, v] of root.nodes) {
        if (k.next.size == 0) {
            res += words[v].length + 1;
        }
    }
    return res;
};