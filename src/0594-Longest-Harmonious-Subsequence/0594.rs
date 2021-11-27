use std::collections::HashMap;

impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for num in nums {
            *cnt.entry(num).or_insert(0) += 1;
        }
        let mut res = 0;
        for (&k, &v) in cnt.iter() {
            if let Some(&c) = cnt.get(&(k + 1)) {
                res = res.max(v + c);
            }
        }
        res
    }
}
