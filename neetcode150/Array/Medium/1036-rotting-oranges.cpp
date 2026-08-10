// ═══════════════════════════════════════════════════════
// Problem: 1036. Rotting Oranges
// Difficulty: Medium
// Topics: Array, Breadth-First Search, Matrix
// Runtime: 0 ms (Beats 100.0%)
// Memory: 17.1 MB (Beats 28.6%)
// Submitted: Aug 10, 2026
// Link: https://leetcode.com/problems/rotting-oranges/
// ═══════════════════════════════════════════════════════

class Solution {
private:
    int rows, cols;
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        queue<pair<int, int>> q;
        int time = 0;
        int fresh = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){                

                if(grid[i][j] == 1){
                    fresh++;
                }else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if(fresh == 0) return 0;

        while(!q.empty() && fresh > 0){
            int size = q.size();
            
            for (int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                for(int d = 0; d < 4; d++){
                    int nr = r + direction[d][0];
                    int nc = c + direction[d][1];
                    if(nc >= 0 && nr >= 0 && nc < cols && nr < rows && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
