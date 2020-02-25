class Solution 
{
public:
    vector<int> closestDivisors(int num) 
    {
        for (int a = sqrt(num + 2); a > 0; --a) 
        {
            if ((num + 1) % a == 0)
                return {a, (num + 1) / a};
            if ((num + 2) % a == 0)
                return {a, (num + 2) / a};
        }
        return {};
    }
};