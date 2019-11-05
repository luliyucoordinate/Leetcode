class Leaderboard {
    private Set<int[]> players = new TreeSet(new Comparator<int[]>() {
        @Override
        public int compare(int[] o1, int[] o2) {
            if (o1[0] == o2[0]) return o1[1] - o2[1];
            return o2[0] - o1[0];
        }
    });
    private Map<Integer, Integer> sc = new HashMap();

    public Leaderboard() {
        
    }
    
    public void addScore(int playerId, int score) {
        if (sc.containsKey(playerId)) {
            players.remove(new int[]{sc.get(playerId), playerId});
            sc.put(playerId, sc.get(playerId) + score);
        } else {
            sc.put(playerId, score);
        }
        players.add(new int[]{sc.get(playerId), playerId});
    }
    
    public int top(int K) {
        int res = 0;
        for (int[] it : players) {
            res += it[0];
            if (--K == 0) break;
        }
        return res;
    }
    
    public void reset(int playerId) {
        players.remove(new int[]{sc.get(playerId), playerId});
        sc.remove(playerId);
    }
}