class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_s = matrix.size();
        if(row_s == 0) return false;
        int col_s = matrix[0].size();
        if(col_s == 0) return false;
       int left {};
       int right = matrix.size() * matrix[0].size() - 1; 
       int mid {};
       while(left <= right){
            mid = left + (right - left)/2;
            int row = mid/ col_s;
            int col = mid% col_s;
            if(matrix[row][col] == target)
                return true;
            else if(target < matrix[row][col]){
                right = mid - 1;
            }
            else 
                left = mid + 1;
       }
       return false;
    }
};
