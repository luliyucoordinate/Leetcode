#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<vector<int>> result(rowIndex+1);
        for (unsigned int i = 0; i <= rowIndex; i++) 
        {
            result[i].resize(i + 1);
            result[i][0] = result[i][i] = 1;
  
            for (unsigned int j = 1; j < i; j++)
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        return result[rowIndex];
    }
};