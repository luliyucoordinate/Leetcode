class Solution 
{
public:
    string minRemoveToMakeValid(string s) 
    {
        vector<int> st; 
        for(int i = 0; i < s.size(); ++i) 
        {
            if (s[i] == '(') st.push_back(i);
            else if (s[i] == ')') 
            {
                if (st.empty()) s[i] = '*';
                else st.pop_back();
            }
        }
        
        while (!st.empty()) 
        {
            s[st.back()] = '*';
            st.pop_back();
        }
        
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};