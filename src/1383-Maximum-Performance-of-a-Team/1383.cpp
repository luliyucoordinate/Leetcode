typedef pair<int, int> PII;
class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<PII> engineers;
        for (int i = 0; i < n; i++)
            engineers.push_back({e[i], s[i]});
        
        sort(engineers.begin(), engineers.end());
        long long res = 0, sSum = 0;
        priority_queue<long long> pq;
        
        for (int i = n - 1; i >= 0; i--) {
            sSum += engineers[i].second;
            res = max(res, sSum * engineers[i].first);
            pq.push(-engineers[i].second);
            if (pq.size() >= k) sSum += pq.top(), pq.pop();
        }
        return res % (int)(1e9 + 7);
    }
};