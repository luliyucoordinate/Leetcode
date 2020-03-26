n = int(input())
g = []
for _ in range(2):
    g.append(list(input().split()))
dp = [[0] * n for _ in range(2)]
dp[0][0] = 1
for i in range(2):
    for j in range(n):
        if g[i][j] == '.':
            if i and j:
                dp[i][j] += dp[i - 1][j - 1]
            if i == 0 and j:
                dp[i][j] += dp[i + 1][j - 1]
            if j:
                dp[i][j] += dp[i][j - 1]
print(dp[-1][-1])


