class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        string res;
        int carry = 0, l1 = a.size(), l2 = b.size();
        while (carry or l1 or l2)
        {
            if (l1) carry += a[--l1] - '0';
            if (l2) carry += b[--l2] - '0';
            res.push_back(carry%2 + '0');
            carry >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};