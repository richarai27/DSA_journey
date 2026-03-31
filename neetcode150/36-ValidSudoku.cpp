class Solution {
  // Time Complexity: O(1) since the board size is fixed (9x9)
  // Space Complexity: O(1) since we are using fixed-size arrays for rows, columns, and squares 
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9]= {0};
        int col[9]= {0};
        int square[9]= {0};

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if (board[r][c] == '.') continue;

                int value = board[r][c] - '1';
                if(row[r] & (1<<value) || col[c] & (1<<value) || square[(r/3)*3 + (c/3)] & (1<<value)) return false;

                row[r]= row[r] | (1<<value);
                col[c]= col[c] | (1<<value);
                square[(r/3)*3 + (c/3)]= square[(r/3)*3 + (c/3)] | (1<<value);
            }
        }
       return true; 
    }
};