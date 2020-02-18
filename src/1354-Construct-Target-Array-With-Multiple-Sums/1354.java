class Solution {
    public boolean isPossible(int[] target) {
        long s = 0;
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
        for (int n : target) {
            s += n;
            q.add(n);
        }      
        
        while (true) {
            int pre = q.poll();
            s -= pre;
            if (pre == 1 || s == 1) return true;
            if (pre < s || pre % s == 0) return false;
            
            pre %= s;
            s += pre;
            q.add(pre);
        }
    }
}