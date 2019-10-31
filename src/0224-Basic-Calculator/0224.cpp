class Solution 
{
public:
    int calculate(string s) 
    {
        vector<int> st;
        int op = 1, r = 0, l = 0;
        for (auto c : s)
        {
            if (c >= '0' && c <= '9') r = r * 10 + (c - '0');
            else if (c == '+' || c == '-')
            {
                l += op * r;
                r = 0, op = c == '+' ? 1 : -1;
            }
            else if (c == '(')
            {
                st.push_back(l);
                st.push_back(op);
                op = 1, l = 0;
            }
            else if (c == ')')
            {
                l += op * r;
                r = 0;
                int tp = st.back(); st.pop_back();
                l = tp * l + st.back(); st.pop_back();
            }
        }
        return l + op * r;
    }
};