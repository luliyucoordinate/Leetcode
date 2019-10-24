/**
 * Initialize your data structure here.
 */
var Trie = function() {
    this.next = {};
    this.isWord = false;
};

/**
 * Inserts a word into the trie. 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    let cur = this;
    for (let c of word) {
        if (!cur.next[c]) {
            cur.next[c] = new Trie();
        }
        cur = cur.next[c];
    }
    if (!cur.isWord) cur.isWord = true;
};


Trie.prototype.find = function(word) {
    let cur = this;
    for (let c of word) {
        if (!cur.next[c]) return null;
        cur = cur.next[c];
    }
    return cur;
};

/**
 * Returns if the word is in the trie. 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    let cur = this.find(word);
    if (cur != null && cur.isWord) return true;
    return false;
};

/**
 * Returns if there is any word in the trie that starts with the given prefix. 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    if (this.find(prefix) != null) return true;
    return false;
};