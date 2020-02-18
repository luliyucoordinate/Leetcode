class Solution 
{
public:
    bool isPossible(vector<int>& target) 
    {
        auto s = accumulate(begin(target), end(target), (long long)0);
        priority_queue<int> q(begin(target), end(target));
        
        while (true) 
        {
            int pre = q.top(); q.pop();
            s -= pre;
            if (pre == 1 || s == 1) return true;
            if (pre < s || pre % s == 0) return false;
            
            pre %= s;
            s += pre;
            q.push(pre);
        }
        return false;
    }
};