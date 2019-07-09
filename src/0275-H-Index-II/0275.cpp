class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        int l = 0, n = citations.size(), r = n -1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (citations[mid] <= n - mid) l = mid;
            else r = mid - 1;
        }
        if (l < n and citations[l] < n - l) return n - l - 1;
        return n - l;
    }
};