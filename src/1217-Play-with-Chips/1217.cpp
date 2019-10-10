class Solution 
{
public:
    int minCostToMoveChips(vector<int>& chips) 
    {
        int res[2] = {0};
        for (int c : chips) res[c%2]++;
        return min(res[0], res[1]);
    }
};