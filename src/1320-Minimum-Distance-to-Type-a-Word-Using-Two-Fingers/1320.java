class Solution {
    public int minimumDistance(String word) {
        int dp[] = new int[26], sum_dis = 0, max_a = 0;
        for (int i = 0; i < word.length() - 1; ++i) {
            int a = word.charAt(i) - 'A', c = word.charAt(i + 1) - 'A';
            for (int b = 0; b < 26; ++b)
                dp[a] = Math.max(dp[a], dp[b] + dis(a, c) - dis(b, c));
            max_a = Math.max(max_a, dp[a]);
            sum_dis += dis(a, c);
        }
        return sum_dis - max_a;
    }

    private int dis(int a, int b) {
        return Math.abs(a / 6 - b / 6) + Math.abs(a % 6 - b % 6);
    }
}