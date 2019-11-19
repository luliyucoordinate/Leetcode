class Solution 
{
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) 
    {
        for (auto& it : synonyms) 
        {
            string x = find(it[0]), y = find(it[1]);
            if (x != y) parent[x] = y;
        }
        for (auto& k : parent) data[find(k.first)].push_back(k.first);
        stringstream ss(text);
        string w;
        
        vector<string> res = {""};
        while (ss >> w) 
        {
            auto fw = find(w);
            if (data.count(fw))
            {
                vector<string> tmp;
                for (auto& s : res)
                {
                    for (auto& v : data[fw])
                    {
                        tmp.push_back(s + " " + v);
                    }
                }
                res = tmp;
            }
            else
            {
                for (auto& s : res)
                    s += " " + w;
            }
        }
        
        for (auto& it : res) it = it.substr(1);
        sort(res.begin(), res.end());
        return res;
    }
private:
    unordered_map<string, string> parent;
    unordered_map<string, vector<string>> data;
    
    string find(const string& x)
    {
        if (!parent.count(x)) parent[x] = x;
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
};