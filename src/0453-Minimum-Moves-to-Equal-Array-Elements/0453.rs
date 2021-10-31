impl Solution {
    pub fn min_moves(nums: Vec<i32>) -> i32 {
        let min_num = nums.iter().min().unwrap();
        let mut res = 0;
        for num in nums.iter() {
            res += num - min_num;
        }
        res
    }
}