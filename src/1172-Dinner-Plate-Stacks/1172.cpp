class DinnerPlates 
{
public:
    DinnerPlates(int capacity) : n(capacity){}
    
    void push(int val) 
    {
        while (!q.empty() and q.top() < stacks.size() and stacks[q.top()].size() == n) q.pop();
        if (q.empty()) q.push(stacks.size());
        if (q.top() == stacks.size()) stacks.push_back({});
        stacks[q.top()].push_back(val);
    }
    
    int pop() 
    {
        while (!stacks.empty() and stacks.back().empty()) stacks.pop_back();
        return popAtStack(stacks.size() - 1);
    }
    
    int popAtStack(int index) 
    {
        if (index >= 0 and index < stacks.size() and !stacks[index].empty()) 
        {
            auto ret = stacks[index].back();
            stacks[index].pop_back();
            q.push(index);
            return ret;
        }
        return -1;
    }
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    vector<vector<int>> stacks;
};
