// ═══════════════════════════════════════════════════════
// Problem: 695. Max Area of Island
// Difficulty: Medium
// Topics: Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
// Runtime: 4 ms (Beats 38.2%)
// Memory: 31.8 MB (Beats 15.4%)
// Submitted: Aug 2, 2026
// Link: https://leetcode.com/problems/max-area-of-island/
// ═══════════════════════════════════════════════════════

class Solution {
private:
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    bfs(grid, i, j, maxArea);                }
            }
        }
        return maxArea;
    }

    void bfs(vector<vector<int>>& grid, int row, int col, int& maxArea){
        queue<pair<int, int>> q;
        q.push({row, col});
        int rows = grid.size();
        int cols = grid[0].size();
        grid[row][col] = 0;
        int area = 1;

        while(! q.empty()){
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for(int i = 0; i < 4; i++){
                int nr = r + direction[i][0];
                int nc = c + direction[i][1];
                
                if(nr < rows && nc < cols && nr >= 0 && nc >= 0 && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    area++;
                    grid[nr][nc] = 0;
                }
            }
        }
        maxArea = max(area, maxArea);
    }
};
