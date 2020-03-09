class Solution {
    public String sortString(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) cnt[c - 'a']++;
        
        StringBuilder res = new StringBuilder();
        while (res.length() < s.length()) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > 0) {
                    res.append((char)('a' + i));
                    --cnt[i];
                }
            }
            
            for (int i = 25; i >= 0; i--) {
                if (cnt[i] > 0) {
                    res.append((char)('a' + i));
                    --cnt[i];
                }
            }
        }
        return res.toString();
    }
}