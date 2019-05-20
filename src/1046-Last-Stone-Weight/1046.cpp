static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        multiset<int> s(begin(stones), end(stones));
        while (s.size() > 1) 
        {
            auto w1 = *prev(s.end());
            s.erase(prev(s.end()));
            auto w2 = *prev(s.end());
            s.erase(prev(s.end()));
            if (abs(w1 - w2) > 0) s.insert(abs(w1 - w2));
        }
        return s.empty() ? 0 : *s.begin();
    }
};