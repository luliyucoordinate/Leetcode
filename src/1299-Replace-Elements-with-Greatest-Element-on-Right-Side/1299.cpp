class Solution 
{
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int max_right = -1;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            max_right = max(arr[i], exchange(arr[i], max_right));
        }
        return arr;
    }
};