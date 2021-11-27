impl Solution {
    pub fn original_digits(s: String) -> String {
        let mut nums = vec![0; 10];
        let mut cnt = vec![0; 26];
        for c in s.as_bytes() {
            cnt[(c - b'a') as usize] += 1;
        }
        nums[0] = cnt[(b'z' - b'a') as usize];
        nums[2] = cnt[(b'w' - b'a') as usize];
        nums[4] = cnt[(b'u' - b'a') as usize];
        nums[6] = cnt[(b'x' - b'a') as usize];
        nums[8] = cnt[(b'g' - b'a') as usize];
        nums[1] = cnt[(b'o' - b'a') as usize] - nums[0] - nums[2] - nums[4];
        nums[3] = cnt[(b'h' - b'a') as usize] - nums[8];
        nums[5] = cnt[(b'f' - b'a') as usize] - nums[4];
        nums[7] = cnt[(b's' - b'a') as usize] - nums[6];
        nums[9] = cnt[(b'i' - b'a') as usize] - nums[5] - nums[6] - nums[8];
        let mut res = String::new();
        for i in 0..10 {
            res.push_str(i.to_string().repeat(nums[i]).as_str());
        }
        res
    }
}
