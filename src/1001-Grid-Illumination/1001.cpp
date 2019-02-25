static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) 
    {
        unordered_map<int, int> r, c, dia1, dia2;
        unordered_set<pair<int, int>, pairHash> lp;
        for (auto& lamp : lamps)
        {
            r[lamp[0]]++, c[lamp[1]]++, dia1[lamp[0]+lamp[1]]++, dia2[lamp[0]-lamp[1]]++;
            lp.insert({lamp[0], lamp[1]});
        }
        
        vector<int> res;
        for (auto& q : queries)
        {
            if (r[q[0]] or c[q[1]] or dia1[q[0] + q[1]] or dia2[q[0] - q[1]]) res.push_back(1);
            else res.push_back(0);
            for (int x = -1; x < 2; ++x)
            {
                for (int y = -1; y < 2; ++y)
                {
                    
                    int nx = x + q[0];
                    int ny = y + q[1];
                    if (lp.erase({nx, ny}))
                    {
                        r[nx]--, c[ny]--, dia1[nx+ny]--,dia2[nx-ny]--;
                    }
                }
            }
        }
        return res;
    }
private:
    struct pairHash
    {
        size_t operator()(const pair<int, int> &x) const { return x.first ^ x.second; }
    };
};