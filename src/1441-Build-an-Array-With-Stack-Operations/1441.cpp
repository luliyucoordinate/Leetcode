class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int k = 1;

        for (int i = 0; i < target.size(); i++, k++) {
            if (target[i] == k) { 
                res.emplace_back("Push");
            } else { 
                i--;
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
        }
        return res;
    }
};