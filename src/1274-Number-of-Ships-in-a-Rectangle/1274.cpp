class Solution 
{
public:
    int countShips(Sea sea, vector<int> tp, vector<int> bl) 
    {
        if (bl[0] > tp[0] || bl[1] > tp[1] || !sea.hasShips(tp, bl)) return 0;
        if (tp[0] == bl[0] && tp[1] == bl[1]) return 1;
        int nx = (tp[0] + bl[0])/2, ny = (tp[1] + bl[1])/2;
        return countShips(sea, {nx, ny}, bl) + 
            countShips(sea, tp, {nx + 1, ny + 1}) + 
            countShips(sea, {nx, tp[1]}, {bl[0], ny + 1}) + 
            countShips(sea, {tp[0], ny}, {nx + 1, bl[1]});
    }
};