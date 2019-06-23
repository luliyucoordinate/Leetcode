class Solution 
{
public:
    vector<double> sampleStats(vector<int>& count) 
    {
        vector<double> res = { 255, 0, 0, 0, 0 };
        int sum_all = accumulate(begin(count), end(count), 0), m_cnt = 0;
        int l = sum_all / 2, r = l + (sum_all & 1 ? 0 : 1);
        for (int i = 0, cnt = 0; i < count.size(); cnt += count[i++]) 
        {
            res[0] = count[i] ? min((int)res[0], i) : res[0];
            res[1] = count[i] ? i : res[1];
            res[2] += (double)i * count[i] / sum_all;

            if (cnt < l && cnt + count[i] >= l) res[3] += (double)i / 2;
            if (cnt < r && cnt + count[i] >= r) res[3] += (double)i / 2;

            res[4] = m_cnt < count[i] ? i : res[4];
            m_cnt = max(m_cnt, count[i]);
        }
        return res;
    }
};