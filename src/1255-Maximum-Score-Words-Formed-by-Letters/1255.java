class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        cnt = new int[score.length];
        n = words.length;
        for (char c : letters) {
            cnt[c - 97]++;
        }
        return dfs(0, words, score);
    }
    
    private int n;
    
    private int[] cnt;
    
    private int dfs(int i, String[] words, int[] score) {
        if (i == n) return 0;
        int res = Math.max(0, dfs(i + 1, words, score)), tmp = 0, val = 1;
        for (char c : words[i].toCharArray()) {
            int t = c - 97;
            cnt[t]--;
            tmp += score[t];
            if (cnt[t] < 0) val = 0;
        }
        if (val == 1) res = Math.max(res, dfs(i + 1, words, score) + tmp);
        for (char c : words[i].toCharArray()) cnt[c - 97]++;
        return res;
    }
}