class Solution 
{
public:
    string generateTheString(int n) 
    {
        return string(n - 1, 'a') + (n % 2 ? 'a' : 'b');
    }
};