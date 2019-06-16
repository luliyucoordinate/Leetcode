class Solution 
{
public:
    vector<string> expand(string S) 
    {
        for (int i = 0; i < S.size(); ++i) 
        {
            if (S[i] == '{')
            {
                string tmp;
                int j = i + 1;
                for (; j < S.size(); ++j) 
                {
                    if (S[j] == '}') break;
                    if (S[j] != ',') tmp.push_back(S[j]);
                }
                data.push_back(tmp);
                i = j;
            }else data.push_back(string(1, S[i]));
        }
        dfs(0, "");
        sort(res.begin(), res.end());
        return res;
    }
private:
    vector<string> data, res;
    
    void dfs(int u, string path)
    {
        if (u == data.size()) 
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < data[u].size(); ++i)
        {
            path.push_back(data[u][i]);
            dfs(u + 1, path);
            path.pop_back();
        }
    }
};