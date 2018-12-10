static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    double myPow(double x, int n) 
    {
        int m = n; 
        double p = 1;
        for(double q = x; m ; m /= 2) 
        {  
            if((m & 1) == 1) p *= q;  
            q *= q;
        }
        return n < 0 ? 1 / p : p;
    }
};