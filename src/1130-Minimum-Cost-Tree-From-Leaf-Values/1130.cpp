class Solution 
{
public:
    int mctFromLeafValues(vector<int>& arr) 
    {
        int res = 0, n = arr.size();
        vector<int> s = {INT_MAX};
        for (int a : arr) 
        {
            while (s.back() <= a)
            {
                int cur = s.back(); s.pop_back();
                res += cur * min(s.back(), a);
            }
            s.push_back(a);
        }
        while (s.size() > 2)
        {
            int cur = s.back(); s.pop_back();
            res += s.back() * cur;
        }
        return res;
    }
};