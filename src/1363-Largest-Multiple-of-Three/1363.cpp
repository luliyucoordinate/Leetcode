class Solution 
{
public:
    string largestMultipleOfThree(vector<int>& digits) 
    {
        int cnt[10] = {};
        for (int i : digits) cnt[i]++;
        int b1 = cnt[1] + cnt[4] + cnt[7], b2 = cnt[2] + cnt[5] + cnt[8];
        int t = (b1 + 2 * b2) % 3;
        
        if (t == 1)
        {
            if (b1 >= 1) b1--;
            else b2 -= 2;
        }
        else if (t == 2)
        {
            if (b2 >= 1) b2--;
            else b1 -= 2;
        }
        
        stringstream in;
        for (int d = 9; d >= 0; d--)
        {
            if (d % 3 == 0) while (cnt[d]-- > 0) in << d;
            else if (d % 3 == 1) while (cnt[d]-- > 0 && b1-- > 0) in << d;
            else while (cnt[d]-- > 0 && b2-- > 0) in << d;
        }
        
        string res; in >> res;
        if (res.size() && res[0] == '0') return "0";
        return res;
    }
};