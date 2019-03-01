static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) 
    {
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first < b.first || (a.first == b.first and a.second > b.second);
        });
        
        vector<int> mem;
        for (auto& e : envelopes)
        {
            auto index = lower_bound(mem.begin(), mem.end(), e.second);
            if (index == mem.end()) mem.push_back(e.second);
            else *index = e.second;
        }
        return mem.size();
    }
};