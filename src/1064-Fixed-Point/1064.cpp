static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int fixedPoint(vector<int>& A) 
    {
        int l = 0, r = A.size()-1;
        while (l <= r) 
        {
            int mid = l + r >> 1;
            if (A[mid] - mid == 0) return mid;
            else if (A[mid] - mid < 0) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};