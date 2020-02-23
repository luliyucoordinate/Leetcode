class Solution {
    public int numberOfSubstrings(String s) {
        int cnt[] = {0, 0, 0}, res = 0 , l = 0, n = s.length();
        
        for (int r = 0; r < n; ++r) {
            ++cnt[s.charAt(r) - 'a'];
            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                res += n - r;
                --cnt[s.charAt(l++) - 'a'];
            }
        }
        return res;
    }
}