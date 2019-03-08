static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool backspaceCompare(string S, string T) 
    {
        int i = S.size()-1, j = T.size()-1;
        int backS = 0, backT = 0;
        while (true)
        {
            while (i >= 0 and (backS or S[i] == '#'))
            {
                backS += S[i] == '#' ? 1 : -1; --i;
            }
            while (j >= 0 and (backT or T[j] == '#'))
            {
                backT += T[j] == '#' ? 1 : -1; --j;
            }
            if (i >= 0 and j >= 0 and S[i] == T[j]) --i, --j;
            else return i == -1 ? i == j : false;
        }
    }
};