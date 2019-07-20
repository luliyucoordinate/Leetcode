class Solution 
{
public:
    int earliestAcq(vector<vector<int>>& logs, int N) 
    {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        s = vector<int>(N + 1, 0);
        for (int i = 0; i <= N; ++i) s[i] = i;
        int cnt = 0;
        for (auto& log : logs)
        {
            int rx = find(log[1]), ry = find(log[2]);
            if (rx != ry)
            {
                s[rx] = ry;
                cnt++;
            }
            if (cnt == N - 1) return log[0];
        }
        return -1;
    }

    vector<int> s;
    int find(int x)
    {
        if (s[x] != x) s[x] = find(s[x]);
        return s[x];
    }
}