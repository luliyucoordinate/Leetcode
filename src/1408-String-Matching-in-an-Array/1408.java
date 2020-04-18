class Solution {
    public List<String> stringMatching(String[] words) {
        Trie root = new Trie();
        for (String word : words) {
            for (int i = 0; i < word.length(); i++) {
                root.insert(word.substring(i));
            }
        }
        
        List<String> res = new ArrayList();
        for (String word : words) {
            if (root.get(word)) res.add(word);
        }
        return res;
    }
}

class Trie {
    public int val;
    public Trie[] next = new Trie[26];

    public void insert(String str) {
        Trie cur = this;
        for (int i = 0; i < str.length(); i++) {
            int j = str.charAt(i) - 'a';
            if (cur.next[j] == null) cur.next[j] = new Trie();
            cur = cur.next[j];
            cur.val++;
        }
    }
    
    public boolean get(String str) {
        Trie cur = this;
        for (int i = 0; i < str.length(); i++) {
            int j = str.charAt(i) - 'a';
            if (cur.next[j] == null) return false;
            cur = cur.next[j];
        }
        return cur.val > 1;
    }
}