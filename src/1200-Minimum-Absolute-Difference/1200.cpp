class Solution 
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int min_dif = INT_MAX;
        vector<vector<int>> res;
        for (int i = 1; i < arr.size(); i++) 
        {
            int dif = arr[i] - arr[i-1];
            if (dif > min_dif) continue;
            else if (dif < min_dif) 
            {
                min_dif = dif;
                res.clear();
            }
            res.push_back({arr[i-1], arr[i]});
        }
        return res;
    }
};