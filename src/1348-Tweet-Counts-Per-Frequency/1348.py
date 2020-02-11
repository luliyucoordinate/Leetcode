class TweetCounts:

    def __init__(self):
        self.tweets = collections.defaultdict(list)
        

    def recordTweet(self, tweetName: str, time: int) -> None:
        bisect.insort_left(self.tweets[tweetName], time)
        

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        delta = 1
        if freq == 'minute':
            delta = 60
        elif freq == 'hour':
            delta = 60 * 60
        elif freq == 'day':
            delta = 60 * 60 * 24
        
        res = [0] * ((endTime - startTime) // delta + 1)
        
        pos = bisect.bisect_left(self.tweets[tweetName], startTime)
        while pos < len(self.tweets[tweetName]) and self.tweets[tweetName][pos] <= endTime:
            res[(self.tweets[tweetName][pos] - startTime) // delta] += 1
            pos += 1
        return res