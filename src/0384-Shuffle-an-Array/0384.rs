use rand::Rng;

struct Solution {
    nums: Vec<i32>,
    org: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(nums: Vec<i32>) -> Self {
        Self {
            nums: nums.clone(),
            org: nums.clone(),
        }
    }

    fn reset(&self) -> Vec<i32> {
        self.org.clone()
    }

    fn shuffle(&self) -> Vec<i32> {
        let mut res = self.nums.clone();
        for i in 0..res.len() {
            let j = i + rand::thread_rng().gen_range(0..res.len() - i);
            res.swap(i, j);
        }
        res
    }
}
