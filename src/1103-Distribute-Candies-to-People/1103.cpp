class Solution 
{
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        vector<int> res(num_people, 0);
        int step = 0;
        while (candies > 0)
        {
            res[step % num_people] += min(candies, step + 1);
            step++;
            candies -= step;
        }
        return res;
    }
};