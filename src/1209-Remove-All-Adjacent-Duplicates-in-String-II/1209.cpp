class Solution 
{
public:
    string removeDuplicates(string s, int k) 
    {
        vector<pair<char, int>> st ={{'#', 0}};
        for (char c : s) 
        {
            if (st.back().first == c) 
            {
                st.back().second++;
                if (st.back().second == k) st.pop_back();
            } 
            else
            {
                st.push_back({c, 1});
            }
        }
        
        string res;
        for (auto& it : st) res += string(it.second, it.first);
        return res;
    }
};