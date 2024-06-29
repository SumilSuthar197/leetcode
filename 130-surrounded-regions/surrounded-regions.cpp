class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board,
             vector<vector<char>>& vis) {
        // cout << r << " " << c << "\n";
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
            board[r][c] == 'X' || vis[r][c] == 'O')
            return;

        vis[r][c] = 'O';
        dfs(r - 1, c, board, vis);
        dfs(r, c - 1, board, vis);
        dfs(r + 1, c, board, vis);
        dfs(r, c + 1, board, vis);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<char>> vis(n, vector<char>(m, 'X'));

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && vis[0][i] != 'O') {
                dfs(0, i, board, vis);
            }
            if (0 != n - 1 && board[n - 1][i] == 'O' && vis[n - 1][i] != 'O') {
                dfs(n - 1, i, board, vis);
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if (board[i][0] == 'O' && vis[i][0] != 'O') {
                dfs(i, 0, board, vis);
            }
            if (0 != m - 1 && board[i][m - 1] == 'O' && vis[i][m - 1] != 'O') {
                dfs(i, m - 1, board, vis);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = vis[i][j];
            }
        }
    }
};