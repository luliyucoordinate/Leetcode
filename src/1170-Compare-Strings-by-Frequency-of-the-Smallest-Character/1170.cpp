class Solution 
{
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) 
    {
        vector<int> res(queries.size(), 0);
        vector<int> w;

        for (auto& word: words) w.push_back(f(word));
        sort(w.begin(), w.end());

        for (int i = 0 ; i < queries.size(); ++i)
        {
            int count = f(queries[i]);
            res[i] = w.end() - upper_bound(w.begin(), w.end(), count);
        }

        return res;
    }

    int f(const string &str)
    {
        int count = 0, minChar = 128;
        for (char c : str)
        {
            if (c < minChar) minChar = c, count = 1;
            else if (c == minChar) ++count;
        }
        return count;
    }
};