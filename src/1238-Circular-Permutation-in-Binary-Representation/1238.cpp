class Solution 
{
public:
    vector<int> circularPermutation(int n, int start) 
    {
        vector<int> res;
        for (int i = 0; i < (1 << n); i++) res.push_back(start^i^(i >> 1));
        return res;
    }
};