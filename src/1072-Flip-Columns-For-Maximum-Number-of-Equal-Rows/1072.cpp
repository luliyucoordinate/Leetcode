class Solution 
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        unordered_map<string, int> m;
        stringstream ss;
        string cur;
        int res = 0;
        
        for (auto& r : matrix)
        {
            ss.clear();
            for (int c : r) ss << (c ^ r[0]);
            ss >> cur;
            res = max(res, ++m[cur]);
        }
        return res;
    }
};