class TweetCounts 
{
public:
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) 
    {
        tweets[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) 
    {
        int delta = 0;
        if (freq == "minute") delta = 60;
        else if (freq == "hour") delta = 60 * 60;
        else if (freq == "day") delta = 60 * 60 * 24;
        
        vector<int> res((endTime - startTime) / delta + 1);
        
        const auto pos = tweets.find(tweetName);
        if (pos != tweets.end()) 
        {
            for (auto t = pos->second.lower_bound(startTime); t != pos->second.end() && *t <= endTime; ++t) 
               ++res[(*t - startTime) / delta];
        }
        return res; 
    }
private:
    unordered_map<string, multiset<int>> tweets;
};