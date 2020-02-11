class TweetCounts {

    public TweetCounts() {
        tweets = new HashMap<>();
    }
    
    public void recordTweet(String tweetName, int time) {
        if (!tweets.containsKey(tweetName)) tweets.put(tweetName, new TreeMap());
        TreeMap<Integer, Integer> tweetMap = tweets.get(tweetName);
        tweetMap.put(time, tweetMap.getOrDefault(time, 0) + 1);
    }
    
    public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime) {
        int delta = 0;
        if (freq.equals("minute")) {
            delta = 60;
        } else if (freq.equals("hour")) {
            delta = 3600;
        } else {
            delta = 86400;
        }
        
        int[] res = new int[((endTime - startTime) / delta) + 1];
        
        for (Map.Entry<Integer, Integer> entry : tweets.get(tweetName).subMap(startTime, endTime + 1).entrySet()) {
            res[(entry.getKey() - startTime) / delta] += entry.getValue();
        }
        
        List<Integer> ret = new ArrayList();
        for (int num : res) ret.add(num);
        return ret;
    }
    
    private Map<String, TreeMap<Integer, Integer>> tweets;
}
