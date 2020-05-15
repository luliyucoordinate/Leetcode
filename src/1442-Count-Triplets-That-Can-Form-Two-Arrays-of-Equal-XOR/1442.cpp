class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), res = 0, prefix = 0;
        unordered_map<int, int> cnt = {{0, 1}}, total;
        for (int i = 0; i < n; ++i) {
            prefix ^= arr[i];
            res += cnt[prefix]++ * i - total[prefix];
            total[prefix] += i + 1;
        }
        return res;
    }
};