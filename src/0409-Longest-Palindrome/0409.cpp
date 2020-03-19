class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[128] =  {};
        for (char c : s) cnt[c]++;
        
        int res = 0;
        for (int v : cnt) res += v / 2 * 2;
        return res == s.size() ? res : res + 1;
    }
};