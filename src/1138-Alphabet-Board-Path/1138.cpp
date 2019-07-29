class Solution 
{
public:
    string alphabetBoardPath(string target) 
    {
        string res;
        int x = 0, y = 0;
        for (auto ch : target) 
        {
            int x1 = (ch - 'a') % 5, y1 = (ch - 'a') / 5;
            res += string(max(0, y - y1), 'U') + string(max(0, x1 - x), 'R') +
                string(max(0, x - x1), 'L') + string(max(0, y1 - y), 'D') + "!";
            x = x1, y = y1;
        }
        return res;
    }
};