impl Solution {
    pub fn number_of_boomerangs(points: Vec<Vec<i32>>) -> i32 {
        let mut res = 0;
        let mut cnt = std::collections::HashMap::new();

        for i in 0..points.len() {
            for j in 0..points.len() {
                if i != j {
                    let x = points[i][0] - points[j][0];
                    let y = points[i][1] - points[j][1];
                    *cnt.entry(x * x + y * y).or_insert(0) += 1;
                }
            }
            res += cnt.values().map(|v| v * (v - 1)).sum::<i32>();
            cnt.clear();
        }
        res
    }
}