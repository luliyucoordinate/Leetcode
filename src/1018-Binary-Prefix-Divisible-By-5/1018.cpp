static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<bool> prefixesDivBy5(vector<int>& A) 
    {
       vector<bool> res(A.size());
        for (int i = 0, num = 0; i < A.size(); ++i) 
        {
            num = (num * 2 + A[i]) % 5;
            res[i] = !num;
        }
        return res; 
    }
};
