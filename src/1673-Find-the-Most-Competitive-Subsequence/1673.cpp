class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans(k);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int K = k;
        int x=-1;
        
        for(int i=0; i<=nums.size()-K; ++i)
            pq.push(make_pair(nums[i], i));
        
        for(int i=0; i<K; ++i) {
            while(pq.top().second <= x)
                pq.pop();
            
            ans[i] = nums[pq.top().second];
            x = pq.top().second;

            --k;
            if(k)
                pq.push(make_pair(nums[nums.size()-k], nums.size()-k));
        }
        return ans;
    }
};
