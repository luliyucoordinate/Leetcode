static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minCut(string s) 
    {
        if (s.size() <= 1) return 0;
        
        vector<int> mem(s.size()+1, 0);
        for (int i = 0; i <= s.size(); ++i) mem[i] = i-1;
        
        for(int i = 1; i < s.size(); ++i)
        {
            for(int j = 0; (i - j) >= 0 && (i + j) < s.size() && s[i-j] == s[i+j]; ++j) 
                mem[i+j+1] = min(mem[i+j+1], 1 + mem[i-j]);

            for(int j = 0; (i-j-1) >= 0 && (i+j) < s.size() && s[i-j-1] == s[i+j]; ++j) 
                mem[i+j+1] = min(mem[i+j+1], 1 + mem[i-j-1]);
        }
        return *(mem.rbegin());
    }
};