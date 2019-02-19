static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numSquarefulPerms(vector<int>& A) 
    {
        sort(A.begin(), A.end());
        int res = 0;
        permute(A, 0, res);
        return res;
    }
    
private:
    void permute(vector<int> A, int i, int& res) 
    {
        if (i == A.size()) 
        {
            ++res; return;
        }
        
        for (int j = i; j < A.size(); ++j) 
        {
            if (j > i && A[i] == A[j]) continue;
            
            swap(A[j], A[i]);
            
            if ((i == 0) or pow((int)sqrt(A[i] + A[i-1]), 2) == A[i] + A[i-1])
            {
                permute(A, i + 1, res);
            }
        }
    }
};