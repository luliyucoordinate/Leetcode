class Solution {
    public int maxSatisfaction(int[] s) {
        Arrays.sort(s);
        int res = 0, total = 0, n = s.length;
        
        for (int i = n - 1; i >= 0 && s[i] > -total; --i) {
            total += s[i];
            res += total;
        }
        return res;
    }
}