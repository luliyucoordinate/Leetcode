class Solution {
  public int mergeStones(int[] stones, int K) {
    final int n = stones.length;
    this.K = K;

    // dp[i][j][k] := min cost to merge stones[i..j] into k piles
    dp = new int[n][n][K + 1];
    for (int[][] A : dp)
      Arrays.stream(A).forEach(a -> Arrays.fill(a, kMax));
    prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + stones[i];

    final int cost = mergeStones(stones, 0, n - 1, 1);
    return cost == kMax ? -1 : cost;
  }

  private static final int kMax = (int) 1e9;
  private int K;
  private int[][][] dp;
  private int[] prefix;

  private int mergeStones(final int[] stones, int i, int j, int k) {
    if ((j - i + 1 - k) % (K - 1) != 0)
      return kMax;
    if (i == j)
      return k == 1 ? 0 : kMax;
    if (dp[i][j][k] != kMax)
      return dp[i][j][k];
    if (k == 1)
      return mergeStones(stones, i, j, K) + prefix[j + 1] - prefix[i];

    for (int m = i; m < j; m += K - 1)
      dp[i][j][k] = Math.min(
          dp[i][j][k],
          mergeStones(stones, i, m, 1) +
          mergeStones(stones, m + 1, j, k - 1));

    return dp[i][j][k];
  }
}
