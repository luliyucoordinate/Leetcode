class Solution {
public:
    Solution(vector<int>& w) 
        : gen(random_device{}()), 
        dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }
    
    int pickIndex() {
        return lower_bound(pre.begin(), pre.end(), dis(gen)) - pre.begin();
    }
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre;
};