class Solution 
{
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int n = arr.size();
        for (int i : {n/4, n/2, n*3/4}) 
        {
            auto p = equal_range(arr.begin(), arr.end(), arr[i]);
            if (p.second - p.first > n / 4)
                return arr[i];
        }
        return -1;
    }
};