class NumArray 
{
public:
    NumArray(vector<int>& data) 
    {
        nums = data;
        tree = vector<int>(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) _update(i+1, nums[i]);
    }
    
    void _update(int i, int delta)
    {
        while (i < tree.size())
        {
            tree[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i)
    {
        int res = 0;
        while (i)
        {
            res += tree[i];
            i -= lowbit(i);
        }
        return res;
    }
    
    int lowbit(int x) 
    {
        return x & (-x);
    }
    
    void update(int i, int val) 
    {
        _update(i+1, val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) 
    {
        return query(j + 1) - query(i);
    }
private:
    vector<int> nums, tree;
};