class Solution {
    public String longestPrefix(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        int i = 0, j;
        f[0] = j = -1;
        
        while (i < n) {
            while (j != -1 && s.charAt(i) != s.charAt(j)) j = f[j];
            ++i; ++j;
            f[i] = j;
        }
        return s.substring(0, f[n]);
    }
}