class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int res = 0, total = 0, n = s.size();
        
        for (int i = n - 1; i >= 0 && s[i] > -total; --i) {
            total += s[i];
            res += total;
        }
        return res;
    }
};