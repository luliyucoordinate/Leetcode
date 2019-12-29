class Solution 
{
public:
    int findBestValue(vector<int>& A, int target) 
    {
        sort(A.begin(), A.end(), [](const int& a, const int& b){
            return a > b;
        });
        
        int maxv = A[0];
        while (!A.empty() && target >= A.size() * A.back())
        {
            target -= A.back(); A.pop_back();
        }
        return A.empty() ? maxv : int(target*1.0/A.size() + 0.49);
    }
};