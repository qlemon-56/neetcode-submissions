class Solution {
public:

    vector<vector<int>> g_grid{};
    int maxCount {0}, count {0};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        g_grid = grid;

        for (size_t x = 0; x < g_grid.size(); x++) {
            for (size_t y = 0; y < g_grid[0].size(); y++) {
                if (g_grid[x][y] == 0) continue;
                dfs(x, y);
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        return maxCount;
    }

    void dfs(size_t x, size_t y) {
        
        // check for out of bounds
        if (x < 0 || y < 0 || x >= g_grid.size() || y >= g_grid[0].size()) return;
        
        // check if cell is 0 or 1
        if (g_grid[x][y] == 0) {
            return;
        } else {
            g_grid[x][y] = 0;
            count++;
        }

        // traverse neighbours
        dfs(x+1, y);
        dfs(x, y+1);
        dfs(x-1, y);
        dfs(x, y-1);
    }
};
