class Solution {
    public int consecutiveNumbersSum(int N) {
        int res = 1, i = 3;
        while (N % 2 == 0) N /= 2;
        
        while (i * i <= N) {
            int cnt = 0;
            while (N % i == 0) {
                N /= i;
                cnt++;
            }
            res *= cnt + 1;
            i += 2;
        }
        return N == 1 ? res : res * 2;
    }
}