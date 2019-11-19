class Solution 
{
public:
    string encode(int num) 
    {
        string res;
        num++;
        while (num) 
        {
            res = string(num&1 ? "1" : "0") + res;
            num >>= 1;
        }
        return res.substr(1);
    }
};