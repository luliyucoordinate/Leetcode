class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        cnt = {v: [0] * len(votes[0]) + [v] for v in votes[0]}
        for vote in votes:
            for i, v in enumerate(vote):
                cnt[v][i] -= 1
        return "".join(sorted(votes[0], key=lambda x: cnt[x]))