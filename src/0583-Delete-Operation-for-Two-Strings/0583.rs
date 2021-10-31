impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let m = word1.len();
        let n = word2.len();
        let mut l = vec![vec![0; n + 1]; m + 1];
        let word1 = word1.as_bytes();
        let word2 = word2.as_bytes();
        for i in 1..=m {
            for j in 1..=n {
                if word1[i - 1] == word2[j - 1] {
                    l[i][j] = l[i - 1][j - 1] + 1;
                } else {
                    l[i][j] = l[i - 1][j].max(l[i][j - 1]);
                }
            }
        }
        (m + n - 2 * l[m][n]) as i32
    }
}