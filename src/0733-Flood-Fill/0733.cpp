class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        if (image.empty()) return image;
        this->newColor = newColor, oldColor = image[sr][sc];
        r = image.size(), c = image[0].size();
        if (oldColor == newColor) return image;
        dfs(image, sr, sc);
        return image;
    }
private:
    int oldColor, r, c, newColor;
    int dire[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(vector<vector<int>>& image, int sr, int sc) 
    {
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; ++i) 
        {
            int nx = dire[i][0] + sr, ny = dire[i][1] + sc;
            if (nx >= 0 and nx < r and ny >= 0 and ny < c and image[nx][ny] == oldColor)
            {
                dfs(image, nx, ny);
            }
        }
    }
};