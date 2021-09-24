impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut tmp = Vec::new();
        for num in nums.iter() {
            match tmp.binary_search(num) {
                Ok(_) => (),
                Err(idx) => {
                    if let Some(old) = tmp.get_mut(idx) {
                        *old = *num;
                    } else {
                        tmp.push(*num);
                    }
                }
            }
        }
        tmp.len() as i32
    }
}