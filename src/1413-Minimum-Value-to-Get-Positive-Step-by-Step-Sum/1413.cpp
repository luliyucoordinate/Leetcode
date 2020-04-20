class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int pref = 0, min_pref = 0;
        for (int i : nums) {
            pref += i;
            min_pref = min(min_pref, pref);
        }
        return 1 - min_pref;
    }
};