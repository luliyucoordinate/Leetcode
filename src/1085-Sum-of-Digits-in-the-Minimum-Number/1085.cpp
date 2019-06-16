class Solution 
{
public:
    int sumOfDigits(vector<int>& A) 
    {
        int min_A = *min_element(A.begin(), A.end());
        int res = 0;
        while (min_A)
        {
            res += min_A%10;
            min_A /= 10;
        }
        return !(res & 1);
    }
};