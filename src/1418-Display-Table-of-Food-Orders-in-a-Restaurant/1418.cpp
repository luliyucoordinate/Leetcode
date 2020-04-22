class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        int n = 0, id = 1;
        map<string, int> foods;
        unordered_map<string, int> tf_cnt[501];
        for (auto& order : orders) {
            foods[order[2]] = 0;
            n += !tf_cnt[stoi(order[1])].size();
            tf_cnt[stoi(order[1])][order[2]]++;
        }
        
        vector<vector<string>> res(n + 1, vector<string>(foods.size() + 1, "0"));
        res[0][0] = "Table"; 
        for (auto& f : foods) res[0][f.second = id++] = f.first;
        for (int i = 0, j = 1; i < 501; ++i) {
            if (!tf_cnt[i].empty()) {
                for (auto& it : tf_cnt[i]) res[j][foods[it.first]] = to_string(it.second);
                res[j++][0] = to_string(i);
            }
        }
        return res;
    }
};