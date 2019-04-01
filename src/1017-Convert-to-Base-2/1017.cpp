static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        string res;
        while (N != 0) 
        {
            int rem = N%-2;
            N/=-2;
            if (rem < 0) N++, rem+=2;
            res = to_string(rem) + res;
        }
        return res;
    }
};