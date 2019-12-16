class Solution 
{
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> res;
        for (int i = 1; i < 9; i++)
        {
            int x = i;
            while (x <= high)
            {
                int r = x % 10;
                if (r == 0) break;
                if (x >= low) res.push_back(x);
                x = x * 10 + r + 1;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};