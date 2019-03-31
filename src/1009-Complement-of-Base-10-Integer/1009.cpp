static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int bitwiseComplement(int N) 
    {
        int X = 1;
        while (X < N) 
        {
            X = (X << 1) + 1;
        }
        return X ^ N;
    }
};