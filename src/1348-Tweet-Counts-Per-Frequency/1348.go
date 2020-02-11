type TweetCounts struct {
    tweets map[string][]int
}


func Constructor() TweetCounts {
    this := new(TweetCounts)
    this.tweets = make(map[string][]int)
    return *this
}


func (this *TweetCounts) RecordTweet(tweetName string, time int)  {
    if this.tweets[tweetName] == nil {
        this.tweets[tweetName] = []int{}
    }
    this.tweets[tweetName] = append(this.tweets[tweetName], time)
}


func (this *TweetCounts) GetTweetCountsPerFrequency(freq string, tweetName string, startTime int, endTime int) []int {
    delta := 0
    if freq == "minute" {
        delta = 60
    } else if freq == "hour" {
        delta = 3600
    } else {
        delta = 60* 60 * 24
    }
    
    res := make([]int, (endTime - startTime)/delta + 1)
    if this.tweets[tweetName] != nil {
        for _, v := range this.tweets[tweetName] {
            if v < startTime || v > endTime {
                continue
            }
            res[(v - startTime)/delta]++
        }
    }
    return res
}