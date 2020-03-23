class Solution {
public:
    int getKth(int lo, int hi, int k) {
        int n = hi - lo + 1;
        int res[n];
        for (int i = lo; i <= hi; i++) res[i - lo] = i;
        
        sort(res, res + n, [&](int a, int b) {
            int p1 = cal(a), p2 = cal(b);
            return p1 == p2 ? a < b : p1 < p2;
        });
        return res[k - 1];
    }
private:
    int cal(int x) {
        int res = 0;
        while (x != 1) {
            if (x & 1) x = x * 3 + 1;
            else x >>= 1;
            res++;
        }
        return res;
    }
};