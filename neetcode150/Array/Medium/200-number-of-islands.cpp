// ═══════════════════════════════════════════════════════
// Problem: 200. Number of Islands
// Difficulty: Medium
// Topics: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
// Runtime: 30 ms (Beats 33.3%)
// Memory: 23.5 MB (Beats 26.3%)
// Submitted: Aug 1, 2026
// Link: https://leetcode.com/problems/number-of-islands/
// ═══════════════════════════════════════════════════════

class Solution {
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int island = 0;

        for(int i = 0; i <rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    bfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }

    void bfs(vector<vector<char>>& grid, int r, int c){
        queue<pair<int, int>> q;
        q.push({r, c});
        
        while(!q.empty()){
            auto k = q.front();
            q.pop();
            int row = k.first;
            int col = k.second;

            for(int i = 0; i < 4; i++){
                int nr = row + direction[i][0];
                int nc = col + direction[i][1];

                if(nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1'){
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }
};
