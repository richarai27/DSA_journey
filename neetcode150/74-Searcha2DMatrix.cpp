class Solution {
  // Time complexity: O(log m + log n) where m is the number of rows and n is the number of columns
  // Space complexity: O(1)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        int topRow = 0, bottomRow = rows - 1;
        int midRow;
        while(topRow <= bottomRow){
            midRow = (topRow + bottomRow) / 2;

            if(target > matrix[midRow][cols - 1]){
                topRow = midRow + 1;
            }
            else if(target < matrix[midRow][0]){
                bottomRow = midRow - 1;
            }
            else{
                break;
            }
        }
        if(!(topRow <= bottomRow)) return false;
        
        int l = 0, r = cols - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(target == matrix[midRow][mid]){
                return true;
            }
            else if(target < matrix[midRow][mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};