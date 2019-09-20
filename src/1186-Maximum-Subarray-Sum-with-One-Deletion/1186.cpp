class Solution 
{
public:
    int maximumSum(vector<int>& arr) 
    {
        int deleted = 0, notDeleted = 0, res = INT_MIN;
        for (int i = 0; i < arr.size(); ++i)
        {
            deleted = max(deleted + arr[i], arr[i]);
            if (i) deleted = max(deleted, notDeleted);
            notDeleted = max(notDeleted + arr[i], arr[i]);
            res = max(res, deleted);
        }
        return res;
    }
};