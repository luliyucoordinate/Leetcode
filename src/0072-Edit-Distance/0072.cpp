#include <iostream>
#include <string>
#include <vector>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{ 
public:
    int minDistance(string word1, string word2) 
    { 
        int m = word1.size(), n = word2.size();
        vector<vector<int>> mem(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) mem[i][0] = i;
        for (int j = 1; j <= n; j++) mem[0][j] = j;  
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++) 
            {
                mem[i][j] = min(mem[i - 1][j - 1] + (word1[i-1] != word2[j-1]), min(mem[i][j - 1] + 1, mem[i - 1][j] + 1));
            }
        }
        return mem[m][n];
    }
};
int main()
{
    string word1 = "";
    string word2 = "";
    cout << Solution().minDistance(word1, word2) << endl;
    return 0;
}