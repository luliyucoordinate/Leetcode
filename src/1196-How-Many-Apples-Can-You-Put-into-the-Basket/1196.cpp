class Solution 
{
public:
    int maxNumberOfApples(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int res = 0, t = 0;
        for (int i : arr)
        {
            t += i;
            if (t > 5000) break;
            res++;
        }
        return res;
    }
};