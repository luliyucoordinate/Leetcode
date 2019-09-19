iclass Solution 
{
public:
    int distanceBetweenBusStops(vector<int>& d, int l, int r) 
    {
        if (l > r) swap(l, r);
        int k = 0, v = 0;
        for (int i = 0; i < d.size(); i++)
        {
            if (i < l or i >= r) k += d[i];
            else v += d[i];
        }
        return min(k, v);
    }
};