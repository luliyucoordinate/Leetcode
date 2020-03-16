class CustomStack {
public:
    CustomStack(int maxSize) : c(maxSize) {}
    
    void push(int x) {
        if (s.size() < c) {
            s.emplace_back(x);
            inc.emplace_back(0);
        }
    }
    
    int pop() {
        if (s.empty()) return -1;
        if (inc.size() > 1) {
            inc[inc.size() - 2] += inc.back();
        }
        int res = s.back() + inc.back();
        s.pop_back(); inc.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        if (!inc.empty()) {
            inc[min(k, int(inc.size())) - 1] += val;
        }
    }
    
private:
    vector<int> s, inc;
    int c;
};