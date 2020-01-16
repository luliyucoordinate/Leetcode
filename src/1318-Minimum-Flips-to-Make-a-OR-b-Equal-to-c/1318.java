class Solution {
    public int minFlips(int a, int b, int c) {
        int res = 0;
        while (a > 0 || b > 0 || c > 0) {
            if ((c & 1) == 1) res += ((a & 1) == 1) || ((b & 1) == 1) ? 0 : 1;
            else res += (a & 1) + (b & 1);
            a >>= 1; b >>= 1; c >>= 1;
        }
        return res;
    }
}