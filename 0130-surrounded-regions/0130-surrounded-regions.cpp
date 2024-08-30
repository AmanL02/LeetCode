class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis, vector<pair<int, int>>& dir) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for (auto it : dir) {
            int nrow = row + it.first;
            int ncol = col + it.second;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow,ncol,board,vis,dir);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, board, vis, dir);
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, board, vis, dir);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, board, vis, dir);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, board, vis, dir);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};