class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, vector<pair<int, int>>& dir) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        for (auto it : dir) {
            int nrow = row + it.first;
            int ncol = col + it.second;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, dir);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis, dir);
            }
            if (!vis[n - 1][j] && grid[n - 1][j] == 1) {
                dfs(n - 1, j, grid, vis, dir);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(i,0, grid, vis, dir);
            }
            if (!vis[i][m - 1] && grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid, vis, dir);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};