class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:   //DFS better
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int row = board.size(), col = board[0].size();
        for (int r = 0; r < row; r++){
            if (board[r][0] == 'O') dfs(r, 0, board);
            if (board[r][col - 1] == 'O') dfs(r, col -1, board);            
        }
        for (int c = 0; c < col; c++){
            if (board[0][c] == 'O') dfs(0, c, board);
            if (board[row - 1][c] == 'O') dfs(row - 1, c, board);
        }
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++){
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }
    void dfs(int r, int c, vector<vector<char>>& board){
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == 'X' || board[r][c] == '#') return;
        board[r][c] = '#';
        for (auto& dir : directions){
            dfs(r + dir.first, c + dir.second, board);
        }
    }
};
