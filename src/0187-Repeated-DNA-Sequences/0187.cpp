static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        if (s.size() < 10) return {};
        unordered_set<string> res, mem;
        for (int i = 0; i < s.size()-9; ++i)
        {
            string cur = s.substr(i, 10);
            if (mem.count(cur)) res.insert(cur);
            else mem.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};