class Solution 
{
public:
    string reverseParentheses(string s) 
    {
        vector<int> st;
        unordered_map<int, int> pa;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') st.push_back(i);
            if (s[i] == ')')
            {
                auto j = st.back(); st.pop_back();
                pa[i] = j; pa[j] = i;
            }
        }
        
        string res;
        int i = 0, d = 1, sLen = s.size();
        while (i < sLen)
        {
            if (s[i] == ')' or s[i] == '(')
            {
                i = pa[i]; d = -d;
            } else res += s[i];
            i += d;
        }
        return res;
    }
};