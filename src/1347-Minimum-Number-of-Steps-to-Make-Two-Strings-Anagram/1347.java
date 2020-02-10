class Solution {
    public int minSteps(String s, String t) {
        int[] cnt = new int[26];
        int n = s.length(), res = 0;
        
        for (int i = 0; i < n; i++) {
            ++cnt[s.charAt(i) - 'a']; 
            --cnt[t.charAt(i) - 'a'];   
        }
        
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) res += cnt[i];
        }
        return res;
    }
}