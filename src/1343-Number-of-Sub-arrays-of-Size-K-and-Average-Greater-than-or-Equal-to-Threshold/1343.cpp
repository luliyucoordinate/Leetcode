class Solution 
{
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int s = 0, n = arr.size(), res = 0, t = k * threshold;
        for (int i = 0; i < k - 1; i++) s += arr[i];
        
        for (int l = 0; l < n - k + 1; l++)
        {
            s += arr[l + k - 1];
            if (s >= t) ++res;
            s -= arr[l];
        }
        return res;
    }
};