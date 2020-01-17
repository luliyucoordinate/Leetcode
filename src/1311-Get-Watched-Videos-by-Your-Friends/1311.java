class Solution {
    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        int[] seen = new int[friends.length];
        Queue<Integer> q = new LinkedList();
        q.offer(id); 
        seen[id] = 1;
        
        while (level-- > 0) {
            for (int i = q.size(); i > 0; i--) {
                int idx = q.poll();
                for (int p : friends[idx]) {
                    if (seen[p] == 0) {
                        seen[p] = 1;
                        q.offer(p);
                    }
                }
            }
        }
        
        Map<String, Integer> cnt = new HashMap();
        while (!q.isEmpty()) {
            for (String s : watchedVideos.get(q.poll())) cnt.put(s, cnt.getOrDefault(s, 0) + 1);
        }
        
        List<String> res = new ArrayList();
        for (String key : cnt.keySet()) {
            res.add(key);
        }
        res.sort((a, b) -> {
            if (cnt.get(a) == cnt.get(b)) return a.compareTo(b);
            else return cnt.get(a) - cnt.get(b);
        });
        return res;
    }
}