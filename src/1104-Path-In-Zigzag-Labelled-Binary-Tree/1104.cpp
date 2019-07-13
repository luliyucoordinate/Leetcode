class Solution 
{
public:
    vector<int> pathInZigZagTree(int label) 
    {
        vector<int> res;
        while (true)
        {
            res.emplace_back(label);
            if (label == 1) break;
            label >>= 1;
            label = label ^ ((1 << int(log2(label))) - 1);
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};