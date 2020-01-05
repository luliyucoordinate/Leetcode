class Solution 
{
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int> A = {0};
        for (int a : arr) A.emplace_back(A.back() ^ a);
        
        vector<int> res;
        for (auto& it : queries) res.emplace_back(A[it[0]] ^ A[it[1] + 1]);
        return res;
    }
};