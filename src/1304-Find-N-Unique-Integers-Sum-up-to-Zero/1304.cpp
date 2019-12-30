class Solution 
{
public:
    vector<int> sumZero(int n) 
    {
        vector<int> res;
        for (int i = 1 - n; i < n; i += 2) res.push_back(i);
        return res;
    }
};