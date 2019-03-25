static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxScoreSightseeingPair(vector<int>& A) 
    {
        int sell = 0, buy = INT_MIN;
        for (int i = 0; i < A.size(); ++i) 
        {
            sell = max(sell, A[i] - i + buy);
            buy = max(buy, A[i] + i);
        }
        return sell;
    }
};