static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) 
    {
        int satisfied = 0, max_add_satisfied = 0, add_satisfied = 0;
        for (int i = 0; i < customers.size(); ++i) 
        {
            satisfied += grumpy[i] ? 0 : customers[i];
            add_satisfied += grumpy[i] ? customers[i] : 0;
            if (i >= X) add_satisfied -= grumpy[i - X] ? customers[i-X] : 0;
            max_add_satisfied = max(max_add_satisfied, add_satisfied);
        }
        return satisfied + max_add_satisfied;
    }
};