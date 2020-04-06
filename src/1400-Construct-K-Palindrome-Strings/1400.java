class Solution {
    public boolean canConstruct(String s, int k) {
        int odds = 0, n = s.length(), count[] = new int[26];
        for (int i = 0; i < n; ++i) {
            count[s.charAt(i) - 'a'] ^= 1;
            odds += count[s.charAt(i) - 'a'] > 0 ? 1 : -1;
        }
        return odds <= k && k <= n;
    }
}