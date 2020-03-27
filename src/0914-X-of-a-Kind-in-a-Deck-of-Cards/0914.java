class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] cnt = new int[10000];
        for (int d : deck) cnt[d]++;

        int res = -1;
        for (int i = 0; i < 10000; i++) {
            if (cnt[i] > 0) {
                if (res == -1) res = cnt[i];
                else res = gcd(res, cnt[i]);
            }
        }
        return res >= 2;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}