class Solution {
public:
    void NQueens(int col, vector<string>& board, vector<vector<string>>& ans,
                 int n, vector<int>& side, vector<int>& lowdiag,
                 vector<int>& uppdiag) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if(side[row]==0 && lowdiag[row+col]==0 && uppdiag[n-1+col-row]==0){
                board[row][col] = 'Q';
                side[row]=1;
                lowdiag[row+col]=1;
                uppdiag[n-1+col-row]=1;
                NQueens(col + 1, board, ans, n, side, lowdiag, uppdiag);
                board[row][col] = '.';
                side[row]=0;
                lowdiag[row+col]=0;
                uppdiag[n-1+col-row]=0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> side(n, 0);
        vector<int> lowdiag(2 * n - 1, 0);
        vector<int> uppdiag(2 * n - 1, 0);
        NQueens(0, board, ans, n, side, lowdiag, uppdiag);
        return ans;
    }
};