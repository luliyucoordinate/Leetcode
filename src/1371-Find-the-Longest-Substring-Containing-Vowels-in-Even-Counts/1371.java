class Solution {
    
    private static final int[] vowels;
    
    static {
        vowels = new int[26];
        vowels['a' - 'a'] = 1;
        vowels['e' - 'a'] = 2;
        vowels['i' - 'a'] = 4;
        vowels['o' - 'a'] = 8;
        vowels['u' - 'a'] = 16;
    }
    
    public int findTheLongestSubstring(String s) {
        int[] vis = new int[32];
        vis[0] = 1; 
        
        char[] cs = s.toCharArray();
        int cur = 0, res = 0;
        for (int i = 0; i < cs.length; i++) {
            cur ^= vowels[cs[i] - 'a'];
            if (vis[cur] == 0) vis[cur] = i + 2;
            res = Math.max(res, i - vis[cur] + 2);
        }
        return res;
    }
}