class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visted(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> qt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    qt.push({{i, j}, 0});
                    visted[i][j] = 1;
                } else {
                    visted[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> dis = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        while (!qt.empty()) {
            auto it = qt.front();
            int row = it.first.first;
            int col = it.first.second;
            int steps = it.second;
            qt.pop();
            ans[row][col] = steps;
            for (auto it : dis) {
                int nrow = row + it.first;
                int ncol = col + it.second;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    visted[nrow][ncol] == 0) {
                        visted[nrow][ncol]=1;
                        qt.push({{nrow,ncol},steps+1});
                }
            }
        }
        return ans;
    }
};