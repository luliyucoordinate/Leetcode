class Leaderboard:
    def __init__(self):
        self.d = collections.defaultdict(int)

    def addScore(self, playerId: int, score: int) -> None:
        self.d[playerId] += score

    def top(self, K: int) -> int:
        return sum(heapq.nlargest(K, self.d.values()))

    def reset(self, playerId: int) -> None:
        del self.d[playerId]