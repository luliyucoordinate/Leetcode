#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string simplifyPath(string path) 
    {
        string result, tmp;
        vector<string> st;
        stringstream s(path);
        while (getline(s, tmp, '/'))
        {
            if (tmp == "." || tmp == "") continue;
            else if (tmp == "..")
            {
                if (!st.empty()) st.pop_back();
            }
            else
            {
                st.push_back(tmp);
            }
        }
        for (auto& i : st)
        {
            result += "/" + i;
        }
        return result.empty() ? "/" : result;
    }
};
int main()
{
    string path = "/...";
    cout << Solution().simplifyPath(path) << endl;
    return 0;
}