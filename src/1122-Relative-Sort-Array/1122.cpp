class Solution 
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int> order(1001, 1001);
        for (int i = 0; i < arr2.size(); ++i) order[arr2[i]] = i;
        for (int i = 0; i < 1001; ++i) 
        {
            if (order[i] == 1001) order[i] = i + 1000;
        }
        sort(arr1.begin(), arr1.end(), [&](const int& a, const int& b){
            return order[a] < order[b];
        });
        return arr1;
    }
};