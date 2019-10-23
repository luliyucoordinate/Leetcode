class Solution 
{
public:
    vector<int> movesToStamp(string stamp, string target) 
    {
        int s_len = stamp.size(), t_len = target.size();
        const auto check = [&](int k) {
            bool res = false;
            for (int i = 0; i < s_len; i++)
            {
                if (target[k + i] != '?')
                {
                    if (target[k + i] != stamp[i]) return false;
                    res = true;
                }
            }
            return res;
        };
        string done(t_len, '?');
        vector<int> res;
        while (target != done)
        {
            bool move = false;
            for (int i = 0; i < t_len - s_len + 1; i++)
            {
                if (check(i))
                {
                    move = true;
                    res.push_back(i);
                    fill(target.begin() + i, target.begin() + i + s_len, '?');
                }
            }
            if (!move) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};