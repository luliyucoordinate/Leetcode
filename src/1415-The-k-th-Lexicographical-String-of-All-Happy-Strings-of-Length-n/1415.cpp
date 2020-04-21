class Solution {
public:
    string getHappyString(int n, int k) {
        int prem = 1 << (n - 1);
        if (k > 3 * prem) return "";
        
        k--;
        string s = string(1, 'a' + k / prem);
        while (prem > 1) {
            k %= prem;
            prem >>= 1;
            s += k / prem == 0 ? 'a' + (s.back() == 'a') : 'b' + (s.back() != 'c');
        }
        return s;
    }
};