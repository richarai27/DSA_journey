// ═══════════════════════════════════════════════════════
// Problem: 130. Surrounded Regions
// Difficulty: Medium
// Topics: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
// Runtime: 0 ms (Beats 100.0%)
// Memory: 14.7 MB (Beats 36.0%)
// Submitted: Aug 22, 2026
// Link: https://leetcode.com/problems/surrounded-regions/
// ═══════════════════════════════════════════════════════

class Solution {
    int rows, cols;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board){
        rows = board.size(); cols = board[0].size();
        if (rows <= 2 || cols <= 2) return;

        for(int i = 0; i < rows; i += rows - 1){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O') bfs(i, j, board);
            }
        }
        for(int j = 0; j < cols; j += cols - 1){
            for(int i = 0; i < rows; i++){
                if(board[i][j] == 'O') bfs(i, j, board);
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'a') board[i][j] = 'O';
                
            }
        }
        return;
    }

private:
    void bfs(int r, int c, vector<vector<char>>& board){
        queue<pair<int, int>> q;
        q.push({r, c});
        board[r][c] = 'a';
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first, col = curr.second;
            for(int d = 0; d < 4; d++){
                int nr = row + directions[d][0];
                int nc = col + directions[d][1];
                if(nr < rows && nc < cols && nr >= 0 && nc >= 0 && board[nr][nc] == 'O'){
                    q.push({nr, nc});
                    board[nr][nc] = 'a';
                }
            }
        }
    }
};
