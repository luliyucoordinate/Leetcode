class CustomStack {
    
    private int c;
    
    private Stack<Integer> s;
    
    private int[] inc;
    
    public CustomStack(int maxSize) {
        c = maxSize;
        s = new Stack();
        inc = new int[c];
    }
    
    public void push(int x) {
        if (s.size() < c) {
            s.push(x);
        }
    }
    
    public int pop() {
        if (s.isEmpty()) return -1;
        
        int i = s.size() - 1;
        if (i > 0) {
            inc[i - 1] += inc[i];
        }
        int res = s.pop() + inc[i];
        inc[i] = 0;
        return res;
    }
    
    public void increment(int k, int val) {
        if (!s.isEmpty()) {
            inc[Math.min(k, s.size()) - 1] += val;
        }
    }
}