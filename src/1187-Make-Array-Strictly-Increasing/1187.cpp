class Solution 
{
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) 
    {
        int l1 = arr1.size(), l2 = arr2.size();
        sort(arr2.begin(), arr2.end());
        unordered_map<int, int> dp = {{0, arr1[0]}, {1, arr2[0]}};
        
        for (int i = 1; i < l1; ++i)
        {
            unordered_map<int, int> ndp;
            for (auto& it : dp)
            {
                if (arr1[i] > it.second and (!ndp.count(it.first) or ndp[it.first] > arr1[i])) ndp[it.first] = arr1[i];
                auto j = upper_bound(arr2.begin(), arr2.end(), it.second) - arr2.begin();
                if (j < l2 and (!ndp.count(it.first+1) or ndp[it.first+1] > arr2[j])) ndp[it.first+1] = arr2[j];
            }
            dp = ndp;
        }
        if (dp.size() == 0) return -1;
        int res = INT_MAX;
        for (auto& it : dp) res = min(res, it.first);
        return res;
    }
};