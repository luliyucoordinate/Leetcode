class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        q, seen = [id], {id}
        for _ in range(level):
            n = len(q)
            for _ in range(n):
                idx = q.pop(0)
                for i in friends[idx]:
                    if i not in seen:
                        q.append(i)
                        seen.add(i)
        
        cnt = collections.Counter([c for idx in q for c in watchedVideos[idx]])
        return sorted(cnt, key=lambda x:(cnt[x], x)) 