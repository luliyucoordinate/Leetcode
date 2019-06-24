class Solution 
{
public:
    int findInMountainArray(int target, MountainArray &m) 
    {
        int p = 0, r = m.length()-1;
        while (p < r)
        {
            int mid = (p + r) >> 1;
            if (m.get(mid) > m.get(mid + 1)) r = mid;
            else p = mid + 1;
        }
        int i = bs(m, target, 0, p, true);
        return i != -1 ?  i : bs(m, target, p+1, m.length()-1, false);
    }
    
    int bs(MountainArray &m, int t, int l, int r, bool asc) 
    {
        while (l < r) 
        {
            int mid = (l + r) >> 1;
            if ((asc and m.get(mid) >= t) or (!asc and m.get(mid) <= t)) r = mid;
            else l = mid + 1;
        }
        if (m.get(l) == t) return l;
        return -1;
    }
};