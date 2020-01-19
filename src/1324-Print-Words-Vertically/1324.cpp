class Solution 
{
public:
    vector<string> printVertically(string s) 
    {
        stringstream ss(s);
        vector<string> strs;
        string str;
        
        while (ss >> str) strs.push_back(str);
        int max_len = 0;
        for (string& st : strs) max_len = max(max_len, (int)st.size());
        
        vector<string> res(max_len);
        for (int j = 0; j < max_len; j++)
        {
            for (string& st : strs)
            {
                if (st.size() > j) res[j] += st[j];
                else res[j] += " ";
            }
        }
        
        for (string& st : res)
        {
            while (!st.empty() && st.back() == ' ') st.pop_back();
        }
        return res;
    }
};