class Solution 
{
public:
    bool isPreString(string& s1, string& s2) 
	{
        int p = 0, n = s1.size();
        for (int i = 0; i < n; i++) 
        {
            if (s1[i] != s2[i + p])
            {
                if (++p != 1) return false;
                else --i;
            }
        }
        return true;
	}
    
    int longestStrChain(vector<string>& words)
	{
		vector<pair<string, int>> mem[17];
		for (auto& w : words) mem[w.size()].emplace_back(w, 1);

		int res = 1;
		for (int i = 2; i <= 16; i++) 
		{
			for (auto& s2 : mem[i])
			{
				for (auto& s1 : mem[i - 1])
				{
					if (isPreString(s1.first, s2.first))
						s2.second = max(s2.second, s1.second + 1);
				}
				res = max(res, s2.second);
			}
		}
		return res;
	}
};