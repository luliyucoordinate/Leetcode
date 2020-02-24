class Solution 
{
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        int d[n] = {};
        for (int i : leftChild) if (i != -1) d[i]++;
        for (int i : rightChild) if (i != -1) d[i]++;
        
        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (d[i] == 0)
            {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;
        
        unordered_set<int> vis = {root};
        queue<int> q; q.push(root);
        while (!q.empty())
        {
            int pre = q.front(); q.pop();
            if (leftChild[pre] != -1) 
            {
                if (vis.count(leftChild[pre])) return false;
                vis.insert(leftChild[pre]);
                q.push(leftChild[pre]);
            }
            if (rightChild[pre] != -1) 
            {
                if (vis.count(rightChild[pre])) return false;
                vis.insert(rightChild[pre]);
                q.push(rightChild[pre]);
            }
        }
        
        return vis.size() == n;
    }
};