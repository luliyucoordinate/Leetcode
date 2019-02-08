static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
  public:
    vector<Interval> intervalIntersection(vector<Interval> &A, vector<Interval> &B)
    {
        vector<Interval> res;
        int i = 0, j = 0;
        while (i < A.size() and j < B.size())
        {
            int l = max(A[i].start, B[j].start);
            int r = min(A[i].end, B[j].end);
            if (l <= r)
                res.push_back(Interval(l, r));
            if (A[i].end < B[j].end)
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return res;
    }
};