class Solution {
    public int longestPalindrome(String s) {
        int[] cnt = new int[128];
        for (char c : s.toCharArray()) cnt[c]++;
        
        int res = 0;
        for (int i : cnt) res += i / 2 * 2;
        return res == s.length() ? res : res + 1;
    }
}