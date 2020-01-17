class Solution 
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        queue<int> q;
        bool seen[friends.size()] = {};
        q.push(id), seen[id] = 1;
        
        while (level--)
        {
            for (int i = q.size(); i > 0; i--)
            {
                int idx = q.front(); q.pop();
                for (int p : friends[idx])
                {
                    if (!seen[p])
                    {
                        q.push(p);
                        seen[p] = 1;
                    }
                }
            }
        }
        
        unordered_map<string, int> cnt;
        while (!q.empty())
        {
            for (string& s : watchedVideos[q.front()]) cnt[s]++;
            q.pop();
        }
        
        vector<string> res;
        for (auto& it : cnt) res.push_back(it.first);
        sort(res.begin(), res.end(), [&](string& a, string& b){
            if (cnt[a] == cnt[b]) return a < b;
            return cnt[a] < cnt[b];
        });
        return res;
    }
};