#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> counter;
        for (auto& per : strs)
        {
            int zeros = count(per.begin(), per.end(), '0');
            int ones = count(per.begin(), per.end(), '1');
            counter.push_back({ zeros, ones });
        }
        auto arr1 = counter;
        sort(arr1.begin(), arr1.end(), [m, n](const vector<int>& s1, const vector<int>& s2) {
            return min(m - s2[0], n - s2[1]) < min(m - s1[0], n - s1[1]);
        });
        auto arr2 = counter;
        sort(arr2.begin(), arr2.end(), [](const vector<int>& s1, const vector<int>& s2) {
            return min(s1[0], s1[1]) < min(s2[0], s2[1]);
        });
        return max(_findMaxForm(arr1, m, n), _findMaxForm(arr2, m, n));
    }
private:
    int _findMaxForm(vector<vector<int>>& arr, int m, int n)
    {
        int result = 0;
        for (auto& per : arr)
        {
            if (m >= per[0] and n >= per[1])
            {
                ++result;
                m -= per[0];
                n -= per[1];
            }
        }
        return result;
    }
};
int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    cout << Solution().findMaxForm(strs, m, n);
    return 0;
}
