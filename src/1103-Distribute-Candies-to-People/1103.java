class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int p = (int)((Math.sqrt(8.0 * candies + 1) - 1) / 2);
        int R = candies - (p + 1) * p / 2;
        int r = p / num_people, c = p % num_people;
        
        int[] res = new int[num_people];
        for (int i = 0; i < num_people; i++) {
            res[i] = (2 * (i + 1) + (r - 1) * num_people) * r / 2;
            if (i < c) res[i] += i + 1 + r * num_people;
        }       
        res[c] += R;
        return res;
    }
}