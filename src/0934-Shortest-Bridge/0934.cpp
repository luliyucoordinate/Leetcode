#include <iostream>
#include <queue>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
private:
    vector<pair<int, int>> edges;
    void getEdges(vector<vector<int>>& A, int x, int y) 
    {
        if (x < 0 || y < 0 || x >= A.size() || 
            y >= A[0].size() || A[x][y] != 1) return;
        if ((x > 0 && A[x-1][y] == 0) || (y+1 < A[0].size() && A[x][y+1] == 0) ||
           (x+1 < A.size() && A[x+1][y] == 0) || (y > 0 && A[x][y-1] == 0)) 
            edges.push_back(make_pair(x, y));
        A[x][y] = 2;
        getEdges(A, x-1, y);
        getEdges(A, x, y+1);
        getEdges(A, x+1, y);
        getEdges(A, x, y-1);
    }
    bool valid(vector<vector<int>>& A, vector<pair<int, int>>& next, int x, int y) 
    {
        if (x < 0 || y < 0 || x >= A.size() || 
            y >= A[0].size() || A[x][y] == 2) 
            return false;
        if (A[x][y] == 1) return true;
        A[x][y] = 2;
        next.push_back(make_pair(x, y));
        return false;
    }
public:
    int shortestBridge(vector<vector<int>>& A) 
    {
        for (int i=0; i<A.size(); ++i) 
        {
            for (int j=0; j<A[i].size(); ++j) 
            {
                if (A[i][j]) 
                {
                    getEdges(A, i, j);
                    goto forward;
                }
            }
        }
    forward:
        int step = 0;
        while (!edges.empty()) 
        {
            step += 1;
            vector<pair<int, int>> next;
            for (int i=0; i<edges.size(); ++i) 
            {
                int x = edges[i].first;
                int y = edges[i].second;
                if (valid(A, next, x-1, y) || valid(A, next, x, y+1) ||
                    valid(A, next, x+1, y) || valid(A, next, x, y-1)) 
                    goto end;
            }
            edges = next;
        }
    end:
        return step - 1;
    }
};
int main()
{
    return 0;
}
