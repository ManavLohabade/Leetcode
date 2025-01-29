// Maximize the number of fish collected by a fisherman in a grid

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }

        int fish = grid[r][c];  // Collect fish
        grid[r][c] = 0;  // Mark as visited

        for (auto& dir : directions) {
            fish += dfs(grid, r + dir[0], c + dir[1]);
        }

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxFish = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {  // Water cell with fish
                    maxFish = max(maxFish, dfs(grid, i, j));
                }
            }
        }

        return maxFish;
    }
};