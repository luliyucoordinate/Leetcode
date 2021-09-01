use rand::{Rng, thread_rng};

struct Solution {
    pre: Vec<i32>,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(w: Vec<i32>) -> Self {
        let mut cur = vec![0; w.len()];
        cur[0] = w[0];
        for i in 1..w.len() {
            cur[i] += cur[i - 1] + w[i];
        }
        Self {pre: cur}
    }
    
    fn pick_index(&self) -> i32 {
        let x = rand::thread_rng().gen_range(1, self.pre.last().unwrap() + 1);
        match self.pre.binary_search(&x) {
            Ok(i) => i as i32,
            Err(i) => i as i32
        }
    }
}