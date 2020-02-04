typedef pair<int, int> PII;
class Solution 
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        priority_queue<PII> q;
        for (int i = 0; i < mat.size(); i++)
        {
            q.push({numOnes(mat[i]), i});
            if (q.size() > k) q.pop();
        }
        
        vector<int> res(k);
        for (int i = k - 1; ~i; i--)
        {
            res[i] = q.top().second;
            q.pop();
        }
        return res;
    }
    
private:
    int numOnes(vector<int>& row)
    {
        int l = 0, r = row.size();
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (row[mid] == 1) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};