class Solution 
{
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) 
    {
        unordered_map<string, string> parent;
        for (auto& region : regions) 
        {
            for (auto it = region.begin() + 1; it != region.end(); it++)
            {
                parent[*it] = region[0];
            }
        }
        string n1 = region1, n2 = region2;
        while (n1 != n2)
        {
            n1 = parent.count(n1) ? parent[n1] : region2;
            n2 = parent.count(n2) ? parent[n2] : region1;
        }
        return n1;
    }
};