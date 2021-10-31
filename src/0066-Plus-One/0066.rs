impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut digits = digits;
        for i in (0..digits.len()).rev() {
            digits[i] = (digits[i] + 1) % 10;
            if digits[i] != 0 {
                return digits;
            }
        }
        digits.insert(0, 1);
        digits
    }
}