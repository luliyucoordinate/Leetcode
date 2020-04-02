class Solution {
   public int numTeams(int[] rating) {
        if (rating.length < 3) return 0;

        int[] leftTree = new int[N + 1];
        int[] rightTree = new int[N + 1];

        for (int r : rating) update(rightTree, r, 1);

        int res = 0;
        for (int r : rating) {
            update(rightTree, r, -1);
            res += getPrefixSum(leftTree, r - 1) * getSuffixSum(rightTree, r + 1) + 
                    getSuffixSum(leftTree, r + 1) * getPrefixSum(rightTree, r - 1);  
            update(leftTree, r, 1);
        }

        return res;
    }
    
    private int N = 100000;
    
    private void update(int[] tr, int x, int v) {
        for (int i = x; i <= N; i += i & -i) tr[i] += v;
    }

    private int getPrefixSum(int[] tr, int x) {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) res += tr[i];
        return res;
    }

    private int getSuffixSum(int[] tr, int i) {
        return getPrefixSum(tr, N) - getPrefixSum(tr, i - 1);
    }
}