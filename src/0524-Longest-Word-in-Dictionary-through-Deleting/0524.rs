impl Solution {
    pub fn find_longest_word(s: String, dictionary: Vec<String>) -> String {
        let n = s.len();
        let mut f = vec![vec![n; 26]; n + 1];
        let ms = s.as_bytes();
        for i in (0..n).rev() {
            for j in 0..26 {
                if ms[i] as usize == j + 97 {
                    f[i][j] = i;
                } else {
                    f[i][j] = f[i + 1][j];
                }
            }
        }
        let mut res = String::from("");
        for w in dictionary {
            let mut state = true;
            let mut j = 0;
            for c in w.as_bytes() {
                if f[j][(c - b'a') as usize] == n {
                    state = false;
                    break;
                }    
                j = f[j][(c - b'a') as usize] + 1;
            }
            if state {
                if res.len() < w.len() ||
                    (res.len() == w.len() && res > w) {
                        res = w;
                }
            }
        }
        res
    }
}
