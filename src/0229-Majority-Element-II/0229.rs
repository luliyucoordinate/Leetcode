impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        nums.iter()
            .fold([(0, 0), (0, 0)], |arr, &i| {
                match arr {
                    [(e, c), d] if e == i => [(e, c + 1), d],
                    [d, (e, c)] if e == i => [d, (e, c + 1)],
                    [(_, c), d] if c == 0 => [(i, 1), d],
                    [d, (_, c)] if c == 0 => [d, (i, 1)],
                    [(e1, c1), (e2, c2)] => [(e1, c1 - 1), (e2, c2 - 1)],             
                }
            })
            .iter()
            .filter(|x| x.1 > 0 && nums.iter().filter(|&i| *i == x.0).count() > nums.len() / 3)
            .map(|x| x.0)
            .collect()
    }
}