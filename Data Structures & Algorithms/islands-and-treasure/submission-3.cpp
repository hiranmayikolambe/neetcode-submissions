class Solution {
    vector<vector<int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        queue<pair<int, int>> q;

        // Add all treasure cells to the queue
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nc < 0 || nr >= row || nc >= col)
                    continue;

                if (grid[nr][nc] != INT_MAX)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
