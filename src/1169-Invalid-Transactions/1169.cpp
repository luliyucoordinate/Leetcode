class Solution 
{
public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        unordered_map<string, vector<tuple<int, string, int>>> data;
        unordered_set<int> delt;
        for (int i = 0; i < transactions.size(); ++i)
        {
            stringstream ss(transactions[i]);
            vector<string> s(4, ""); 
            int k = 0;
            while (getline(ss, s[k++], ','));
            if (stoi(s[2]) > 1000) delt.insert(i);
            data[s[0]].push_back({stoi(s[1]), s[3], i});
        }
        
        for (auto& it : data)
        {
            sort(it.second.begin(), it.second.end());
            deque<tuple<int, string, int>> q;
            for (auto& t1 : it.second)
            {
                while (!q.empty() and get<0>(q.front()) < get<0>(t1) - 60) q.pop_front();
                for (auto& t2 : q)
                {
                    if (get<1>(t1) != get<1>(t2)) 
                    {
                        delt.insert(get<2>(t1)); delt.insert(get<2>(t2));
                    }
                }
                q.emplace_back(t1);
            }
        }
        vector<string> res;
        for (auto& i : delt) res.push_back(transactions[i]);
        return res;
    }
};