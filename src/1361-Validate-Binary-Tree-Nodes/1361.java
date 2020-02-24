class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] d = new int[n];
        for (int i : leftChild) if (i != -1) d[i]++;
        for (int i : rightChild) if (i != -1) d[i]++;
        
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;
        
        Set<Integer> vis = new HashSet();
        Queue<Integer> q = new LinkedList();
        vis.add(root); q.add(root);
        while (!q.isEmpty()) {
            int pre = q.poll();
            if (leftChild[pre] != -1) {
                if (vis.contains(leftChild[pre])) return false;
                vis.add(leftChild[pre]);
                q.add(leftChild[pre]);
            }
            if (rightChild[pre] != -1) {
                if (vis.contains(rightChild[pre])) return false;
                vis.add(rightChild[pre]);
                q.add(rightChild[pre]);
            }
        }
        return vis.size() == n;
    }
}