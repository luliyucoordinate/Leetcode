class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[501] = {};
        for (int i : arr) cnt[i]++;
        
        for (int i = 500; i; i--) {
            if (cnt[i] == i) return i;
        }
        return -1;
    }
};