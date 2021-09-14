impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut res = 1u128;
        for c in s.chars() {
            match c {
                '(' => res <<= 1,
                ')' => res >>= 1,
                _ => res |= (res << 1) | (res >> 1)
            }
        }
        res & 1 != 0
    }
}