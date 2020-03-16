typedef pair<double, int> PDD;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int K) {
        vector<PDD> workers;
        for (int i = 0; i < q.size(); ++i)
            workers.push_back({(double)w[i] / q[i], (double)q[i]});
        
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        
        for (auto& worker : workers) {
            qsum += worker.second;
            if (pq.size() == K - 1) res = min(res, qsum * worker.first);
            pq.push(worker.second);
            if (pq.size() >= K) qsum -= pq.top(), pq.pop();
        }
        return res;
    }
};