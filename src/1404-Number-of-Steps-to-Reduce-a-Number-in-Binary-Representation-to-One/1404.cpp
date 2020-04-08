class Solution {
public:
    int numSteps(string s) {
        int res = 0, add = 0, n = s.size();
        
        for (int i = n - 1; i; i--) {
            res++;
            if (s[i] - '0' + add == 1) {
                add = 1;
                res++;
            }
        }
        return res + add;
    }
};