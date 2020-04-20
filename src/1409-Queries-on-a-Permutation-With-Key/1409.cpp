class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        N = m + n + 1;
        
        int pos[m + 1];
        int tree[N];
        memset(tree, 0, sizeof tree);
        for (int i = 1; i <= m; i++) {
            pos[i] = n + i;
            update(tree, i + n, 1);
        }
        
        vector<int> res;
        for (int i : queries) {
            res.emplace_back(prefixSum(tree, pos[i] - 1));
            update(tree, pos[i], -1);
            update(tree, n, 1);
            pos[i] = n--;
        }
        return res;
    }
private:
    int N;
    
    void update(int tr[], int x, int v) {
        for (int i = x; i < N; i += i & -i) {
            tr[i] += v;
        }
    }
    
    int prefixSum(int tr[], int x) {
        int res = 0;
        for (int i = x; i; i -= i & -i) {
            res += tr[i];
        }
        return res;
    }
};