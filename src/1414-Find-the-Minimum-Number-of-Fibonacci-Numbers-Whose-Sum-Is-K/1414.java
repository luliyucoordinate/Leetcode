class Solution {
    public int findMinFibonacciNumbers(int k) {
        int res = 0, a = 1, b = 1, t;
        while (b <= k) {
            t = a;
            a = b;
            b += t;
        }

        while (a > 0) {
            if (a <= k) {
                k -= a;
                res++;
            }
            t = a;
            a = b - a;
            b = t;
        }
        return res;
    }
}