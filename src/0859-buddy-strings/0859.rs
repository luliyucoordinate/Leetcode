impl Solution {
    pub fn buddy_strings(s: String, goal: String) -> bool {
        let n = s.len();
        if n != goal.len() {
            return false;
        }
        let mut t = 0;
        let mut ok = false;

        let mut a = vec![0; 26];
        let mut b = vec![0; 26];
        let s = s.as_bytes();
        let goal = goal.as_bytes();
        for i in 0..n {
            a[(s[i] - b'a') as usize] += 1;
            b[(goal[i] - b'a') as usize] += 1;
            if s[i] != goal[i] {
                t += 1;
            }
        }

        for i in 0..26 {
            if a[i] != b[i] {
                return false;
            }
            if a[i] > 1 {
                ok = true;
            }
        }
        t == 2 || (t == 0 && ok)
    }
}
