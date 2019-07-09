class Solution 
{
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (r - l)/2 + l;
            if (isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};