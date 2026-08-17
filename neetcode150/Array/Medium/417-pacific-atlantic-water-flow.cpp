// ═══════════════════════════════════════════════════════
// Problem: 417. Pacific Atlantic Water Flow
// Difficulty: Medium
// Topics: Array, Depth-First Search, Breadth-First Search, Matrix
// Runtime: 13 ms (Beats 25.4%)
// Memory: 25 MB (Beats 22.1%)
// Submitted: Aug 17, 2026
// Link: https://leetcode.com/problems/pacific-atlantic-water-flow/
// ═══════════════════════════════════════════════════════

class Solution {
private:
    int ROWS, COLS;
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void bfs(vector<vector<int>>& ocean, queue<pair<int, int>>& q,
             vector<vector<int>>& heights) {
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            ocean[r][c] = 1;

            for (int d = 0; d < 4; d++) {
                int nr = r + direction[d][0], nc = c + direction[d][1];
                if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS &&
                    !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                }
            }
        }
        return;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<int>> pac(ROWS, vector<int>(COLS, 0));
        vector<vector<int>> atl(ROWS, vector<int>(COLS, 0));

        queue<pair<int, int>> pacific, atlantic;
        vector<vector<int>> result;

        for (int r = 0; r < ROWS; r++) {
            pacific.push({r, 0});
            atlantic.push({r, COLS - 1});
        }
        for (int c = 0; c < COLS; c++) {
            pacific.push({0, c});
            atlantic.push({ROWS - 1, c});
        }

        bfs(pac, pacific, heights);
        bfs(atl, atlantic, heights);

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};
