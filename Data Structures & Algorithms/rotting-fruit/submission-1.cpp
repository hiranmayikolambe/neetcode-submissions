class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0, time = 0;
        for (int r = 0; r < grid.size(); r++){
            for (int c = 0; c < grid[0].size(); c++){
                if (grid[r][c] == 1) fresh++;
                if (grid[r][c] == 2) q.push({r, c});
            }            
        }
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (fresh > 0 && !q.empty()){
            int length = q.size();
            for (int i = 0; i < length; i++){
                auto curr = q.front(); q.pop();
                int r = curr.first;
                int c = curr.second;
                for (auto& dir: directions){
                    int nr = r + dir.first;
                    int nc = c + dir.second;
                    if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
