static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    double minAreaFreeRect(vector<vector<int>>& points) 
    {
        unordered_set<string> s;
        double res = 0;
        for (auto a: points)
        {
            s.insert(to_string(a[0]) + "_" + to_string(a[1]));
        }
        
        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                for (int k = j + 1; k < points.size(); ++k)
                {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) != 0) continue;
                    int x4 = x2 + x3 - x1; 
                    int y4 = y2 + y3 - y1;
                    if (s.count(to_string(x4) + "_" + to_string(y4)))
                    {
                        double w = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
                        double l = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);
                        double area = w * l;
                        if (res == 0 || res != 0 && area < res) res = area;
                    }
                }
            }
        }
        return res;
    }
};