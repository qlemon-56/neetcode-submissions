class Solution {
   public:
    int count{0};
    vector<vector<char>> grid_g{};
    vector<vector<int>> seen{};

    int numIslands(vector<vector<char>>& grid) {
        grid_g = grid;

        // what makes an island?
        // if i am 1 and everything aroung me is 0 i am an island
        // if i am 1 and everyything around me is 1 i am part of an island

        // if i am 0 i am not an island
        seen.resize(grid.size(), vector<int>(grid[0].size()));

        for (size_t x = 0; x < grid.size(); x++) {
            for (size_t y = 0; y < grid[0].size(); y++) {

                if (grid[x][y] == '0' ) {
                    seen[x][y] = 1;
                    continue;
                } 
                if (seen[x][y] == 1) continue;
                dfs(x, y);
                count++;
            }
        }
        return count;
    }

    void dfs(size_t x, size_t y) {

        // need to check if node is null
        if (x >= grid_g.size() || x < 0 || y >= grid_g[0].size() || y < 0) return;

        // check if seen already
        if (seen[x][y] == 1) return; seen[x][y] = 1; // mark as seen

        // return early if cell is 0
        if (grid_g[x][y] == '0') return;
        
        // move to neighbours
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x-1, y);
        dfs(x, y-1);
    }
};
