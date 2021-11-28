impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let (n, m) = (s.len(), p.len());
        let mut res = vec![];
        if n < m {
            return res;
        }

        let mut cnt = vec![0; 26];
        let s = s.as_bytes();
        let p = p.as_bytes();
        for i in 0..m {
            let x = (p[i] - b'a') as usize;
            cnt[x] += 1;
        }

        let mut t = m;
        for i in 0..n {
            let x = (s[i] - b'a') as usize;
            if cnt[x] >= 1 {
                t -= 1;
            }
            cnt[x] -= 1;
            if i >= m {
                let x = (s[i - m] - b'a') as usize;
                if cnt[x] >= 0 {
                    t += 1;
                }
                cnt[x] += 1;
            }
            if t == 0 {
                res.push((i - m + 1) as i32);
            }
        }
        res
    }
}
