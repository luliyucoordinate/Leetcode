#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
private:
    static bool cmp(const string &A, const string& B)
    {
        string subA = A.substr(A.find(' ') + 1);
        string subB = B.substr(B.find(' ') + 1);
        if (isdigit(subA[0])) return false;
        else if (isdigit(subB[0])) return true;
        return subA.compare(subB) < 0;
    }
};

int main()
{
    vector<string> logs = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    cout << Solution().reorderLogFiles(logs);
    return 0;
}
