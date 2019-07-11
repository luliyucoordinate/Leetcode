class Solution 
{
public:
    vector<string> braceExpansionII(string expression) 
    {
        this->s = expression + "}";
        int i = 0;
        auto res = solve(i);
        return res;
    }
    
private:
    string s;
    vector<string> _merge(vector<string>& a, vector<string>& b) 
    {
        vector<string> res;
        for (auto& l : a) 
        {
            for (auto & r : b) 
            {
                res.push_back(l + r);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    vector<string> solve(int& i) 
    {
        if (s[i] != '{') {
            vector<string> L = {string(1, s[i])};
            i++;
            if (s[i] == '}' || s[i] == ',') return L;
            auto R = solve(i);
            return _merge(L, R);
        }
        
        set<string> all;
        while (s[i] != '}') 
        {
            ++i;
            auto R = solve(i);
            for (auto& it : R) all.insert(it);
        }
        vector<string> L(all.begin(), all.end());
        ++i;
        if (s[i] == '}' || s[i] == ',') return L;
        auto R = solve(i);
        return _merge(L, R);
    }
};