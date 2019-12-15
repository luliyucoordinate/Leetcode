class CombinationIterator {

    public CombinationIterator(String ch, int l) {
        combine(0, l, new StringBuilder(), ch);
    }
    
    private Queue<String> q = new LinkedList();
    
    private void combine(int s, int k, StringBuilder cur, String ch) {
        if (cur.length() == k) {
            q.offer(cur.toString());
            return;
        }
        
        for (int i = s; i <= ch.length() - (k - cur.length()); i++) {
            cur.append(ch.charAt(i));
            combine(i + 1, k, cur, ch);
            cur.deleteCharAt(cur.length() - 1);
        }
    }
    
    public String next() {
        return q.poll();
    }
    
    public boolean hasNext() {
        return !q.isEmpty();
    }
}