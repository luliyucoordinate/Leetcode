class Solution {
    public int uniqueLetterString(String S) {
        int res = 0, f = 0, mod = 1000000007;
        int[] m = new int[26];
        int[] n = new int[26];
        for (int i = 0; i < S.length(); i++) {
            int t = S.charAt(i) - 'A';
            f = f + 1 + i - 2* m[t] + n[t];
            res = (res + f) % mod;
            n[t] = m[t];
            m[t] = i + 1;
        }
        return res;
    }
}