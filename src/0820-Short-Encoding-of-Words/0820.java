class Solution {
    public int minimumLengthEncoding(String[] words) {
        Trie root = new Trie();
        for (int i = 0; i < words.length; i++) root.insert(words[i], i);

        int res = 0;
        for (Map.Entry<Node, Integer> it : root.nodes.entrySet()) {
            if (it.getKey().next.isEmpty()) {
                res += words[it.getValue()].length() + 1;
            }
        }
        return res;
    }
}

class Node {
    public Map<Character, Node> next = new HashMap();
}

class Trie {
    private Node root = new Node();
    public Map<Node, Integer> nodes = new HashMap();

    public void insert(String str, int id) {
        Node cur = root;
        for (int i = str.length() - 1; i >= 0; i--) {
            char j = str.charAt(i);
            if (!cur.next.containsKey(j)) cur.next.put(j, new Node());
            cur = cur.next.get(j);
        }
        nodes.put(cur, id);
    }
}