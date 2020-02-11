var TweetCounts = function() {
    this.tweets = new Map();
};

/** 
 * @param {string} tweetName 
 * @param {number} time
 * @return {void}
 */
TweetCounts.prototype.recordTweet = function(tweetName, time) {
    if (!this.tweets.has(tweetName)) this.tweets.set(tweetName, []);
    this.tweets.get(tweetName).push(time);
};

/** 
 * @param {string} freq 
 * @param {string} tweetName 
 * @param {number} startTime 
 * @param {number} endTime
 * @return {number[]}
 */
TweetCounts.prototype.getTweetCountsPerFrequency = function(freq, tweetName, startTime, endTime) {
    let delta = 0;
    if (freq == "minute") delta = 60;
    else if (freq == "hour") delta = 60 * 60;
    else if (freq == "day") delta = 60 * 60 * 24;
    
    let res = Array(Math.floor((endTime - startTime) / delta) + 1).fill(0);
    if (this.tweets.has(tweetName)) {
        for (let v of this.tweets.get(tweetName)) {
            if (v < startTime || v > endTime) continue;
            res[Math.floor((v - startTime) / delta)]++;
        }
    }
    return res;
};