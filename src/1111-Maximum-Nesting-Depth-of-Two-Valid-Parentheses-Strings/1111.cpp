class Solution 
{
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        vector<int> res(seq.size(), 0);
        for (int i = 0; i < seq.size(); ++i)
        {
            res[i] = i & 1 ^ (seq[i] == ')');
        }
        return res;
    }
};