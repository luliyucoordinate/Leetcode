class Solution 
{
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        long long n = numerator, d = denominator;
        bool flag = true;
        if (n < 0) flag = !flag, n = -n;
        if (d < 0) flag = !flag, d = -d;
        string res = to_string(n/d);
        n %= d;
        if (n == 0) 
        {
            if (!flag and res != "0") return "-" + res;
            return res;
        }
        
        res += '.';
        unordered_map<long long, int> m;
        while (n) 
        {
            if (m.count(n)) 
            {
                res = res.substr(0, m[n]) + "(" + res.substr(m[n]) +")";
                break;
            }
            else m[n] = res.size();
            n *= 10ll;
            res += to_string(n/d);
            n %= d;
        }
        return flag ? res : "-" + res;
    }
};