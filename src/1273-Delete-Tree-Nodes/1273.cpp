class Solution 
{
public:
    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) 
    {
        for (int i = n - 1; i > 0; i--) value[parent[i]] += value[i];
        int zeros = 0;
        bool isZero[n] = {};
        for (int i = 0; i < n; i++)
        {
            if (parent[i] > 0 && isZero[parent[i]] || value[i] == 0)
            {
                isZero[i] = true; zeros++;
            }
        }
        return n - zeros;
    }
};