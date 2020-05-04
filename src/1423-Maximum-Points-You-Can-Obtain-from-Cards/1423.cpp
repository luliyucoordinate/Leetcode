class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0, cur = 0, n = cardPoints.size();
        for (int i = n - k; i < n + k; i++) {
            cur += cardPoints[i % n];
            if (i >= n) cur -= cardPoints[i - k];
            res = max(res, cur);
        }
        return res;
    }
};