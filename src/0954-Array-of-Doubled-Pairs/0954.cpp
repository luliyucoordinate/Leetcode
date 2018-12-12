static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool canReorderDoubled(vector<int>& A) 
    {
        map<int, int> A_dict;
        vector<int> keys;
        for (auto a : A) A_dict[a]++;
        for (auto& a: A_dict) keys.push_back(a.first);
        sort(keys.begin(), keys.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        for (auto k : keys)
        {
            if (A_dict[k] > A_dict[k*2]) return false;
            A_dict[2*k] -= A_dict[k];
        }
        return true;
    }
};