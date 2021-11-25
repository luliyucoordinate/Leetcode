impl Solution {
    pub fn poor_pigs(buckets: i32, minutes_to_die: i32, minutes_to_test: i32) -> i32 {
        let states = minutes_to_test / minutes_to_die + 1;
        ((buckets as f32).log2() / (states as f32).log2()).ceil() as i32
    }
}
