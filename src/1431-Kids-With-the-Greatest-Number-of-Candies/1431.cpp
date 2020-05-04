class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int m = *max_element(candies.begin(), candies.end());
        for (int i : candies) {
            res.emplace_back(extraCandies + i >= m);
        }
        return res;
    }
};