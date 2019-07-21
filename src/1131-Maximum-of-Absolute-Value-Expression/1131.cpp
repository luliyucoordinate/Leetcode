class Solution 
{
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) 
    {
        int res = 0, n = arr1.size();
        int dire[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        for (auto& d : dire)
        {
            int r = arr1[0]*d[0] + arr2[0]*d[1];
            for (int i = 0; i < n; ++i)
            {
                int l = arr1[i]*d[0] + arr2[i]*d[1] + i;
                res = max(res, l - r);
                r = min(l, r);
            }
        }
        return res;
    }
};