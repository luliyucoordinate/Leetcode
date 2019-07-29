class Solution 
{
public:
    int tribonacci(int n) 
    {
        if (dict.count(n)) return dict[n];
        else tri(35);
        return dict[n];
    }
private:
    unordered_map<int, int> dict;
    void tri(int n)
    {
        int a = 0, b = 1, c = 1, k = 3;
        dict[0] = 0, dict[1] = 1, dict[2] = 1;
        while (n--)
        {
            int t = c;
            c = a + b + c; a = b; b = t;
            dict[k++] = c;
        }
    }
};