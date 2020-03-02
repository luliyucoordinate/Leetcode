class Solution {
    public String rankTeams(String[] votes) {
        int n = votes[0].length();
        int[][] cnt = new int[26][n + 1];
        for (int i = 0; i < 26; i++) cnt[i][n] = i;
        
        for (String vote : votes) {
            for (int i = 0; i < n; i++) {
                cnt[vote.charAt(i) - 'A'][i]--;
            }
        }
        
        Character[] res = new Character[n];
        for (int i = 0; i < n; i++) res[i] = votes[0].charAt(i);
        Arrays.sort(res, (a, b) -> Arrays.compare(cnt[a - 'A'], cnt[b - 'A'])); // Java 9
        
        StringBuilder ss = new StringBuilder();
        for (char s : res) ss.append(s);
        return ss.toString();
    }
}