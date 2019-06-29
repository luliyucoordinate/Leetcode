class Solution 
{
public:
    bool isRobotBounded(string instructions) 
    {
        int x = 0, y = 0, s = 0;
        int dire[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        for (char c : instructions)
        {
            switch (c)
            {
            case 'G':
                x += dire[s][0];
                y += dire[s][1];
                break;
            case 'L':
                s = (s + 1) % 4;
                break;
            case 'R':
                s = (s + 3) % 4;
                break;
            }
        }
        return x == 0 and y == 0 or s > 0;
    }
};