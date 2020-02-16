class ProductOfNumbers 
{
public:
    ProductOfNumbers() {}
    
    void add(int num) 
    {
        if (num == 0) pre = {1};
        else pre.push_back(pre.back() * num);
    }
    
    int getProduct(int k) 
    {
        if (pre.size() <= k) return 0;
        return pre.back() / pre[pre.size() - k - 1];
    }
    
private:
    vector<int> pre = {1};
};