static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isNStraightHand(vector<int>& hand, int W) 
    {
        map<int, int> c;
        for (int i : hand) c[i]++;
        for (auto it : c)
        {
            if (c[it.first] > 0)
            {
                for (int i = W - 1; i >= 0; --i)
                    if ((c[it.first + i] -= c[it.first]) < 0)
                        return false;
            }  
        }
        return true;
    }
};