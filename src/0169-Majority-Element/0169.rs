impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut cnt = 0;
        let mut res = 0;
        for num in nums.into_iter() {
            if cnt == 0 {
                res = num;
            } 
            cnt += if res == num {1} else {-1}
        }
        res
    }
}