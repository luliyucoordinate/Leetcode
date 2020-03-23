class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> cnt;
        for (auto& t : reservedSeats) {
            cnt[t[0]] |= 1 << (t[1] - 1);
        }
        
        int res = 0, q1 = 0b111111110, q2 = 0b111100000, q3 = 0b000011110, q4 = 0b001111000;
        for (auto& [k, v] : cnt) {
            if (!(q1 & v)) res += 2;
            else if (!(q2 & v) || !(q3 & v) || !(q4 & v)) res++;
        }
        return res + (n - cnt.size()) * 2;
    }
};