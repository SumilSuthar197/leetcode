class Solution {
public:
    int time = 0;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
        while (!q.empty()) {
            auto [x, y] = q.front().first;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for (auto d : dir) {
                int row = x + d.first;
                int col = y + d.second;

                if (row < 0 || row >= n || col < 0 || col >= m ||
                    grid[row][col] != 1)
                    continue;
                q.push({{row, col}, t + 1});
                grid[row][col] = 2;
            }
        };
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return -1;
        return time;
    }
};