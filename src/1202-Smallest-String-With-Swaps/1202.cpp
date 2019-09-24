class Solution 
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        for (int i = 0; i < s.size(); i++) p.push_back(i);
        for (auto& it : pairs)
        {
            int px = find(it[0]), py = find(it[1]);
            if (px != py) p[px] = py;
        }
        
        unordered_map<int, vector<int>> mem;
        for (int i = 0; i < p.size(); i++) 
        {
            mem[find(p[i])].push_back(s[i]);
        }
        
        for (auto& it : mem) sort(it.second.begin(), it.second.end(), greater<int>());
        
        string res;
        for (int i = 0; i < s.size(); i++) 
        {
            int x = find(i);
            res.push_back(mem[x].back());
            mem[x].pop_back();
        }
        return res;
    }
    
private:
    vector<int> p;
    
    int find(int x)
    {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }
};