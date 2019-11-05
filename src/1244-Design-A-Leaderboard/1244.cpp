class Leaderboard 
{
public:
    Leaderboard() {}
    
    void addScore(int playerId, int score) 
    {
        players.erase({sc[playerId], playerId});
        sc[playerId] += score;
        players.insert({sc[playerId], playerId});
    }
    
    int top(int K)
    {
        int res = 0;        
        for (auto it = players.rbegin(); it != players.rend() && K > 0; ++it, --K) 
            res += it->first;
        return res;
    }
    
    void reset(int playerId) 
    {
        players.erase({sc[playerId], playerId});        
        sc.erase(playerId);
    }

private:
    set<pair<int, int>> players;
    unordered_map<int, int> sc;
};