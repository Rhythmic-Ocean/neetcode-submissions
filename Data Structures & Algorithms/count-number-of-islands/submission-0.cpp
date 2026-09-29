class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int islands {};
       for(int i {}; i < grid.size(); ++i){
        for(int j {}; j < grid[0].size(); ++j){
            if(grid[i][j] == '1'){
                ++islands;
                dfs(grid, i, j);
            }
        }
       } 
    return islands;
    }
    void dfs(vector<vector<char>>& grid, int rw, int col){
        int mx_rw = grid.size() - 1;
        int mx_col = grid[0].size() - 1;
        grid[rw][col] = '0';
        if(rw != 0 && grid[rw-1][col]=='1'){
            dfs(grid, rw-1, col);
        }
        if(col != 0 && grid[rw][col-1] == '1'){
            dfs(grid, rw, col - 1);
        }
        if(rw != mx_rw && grid[rw + 1][col] == '1'){
            dfs(grid, rw + 1, col);
        }
        if(col != mx_col && grid[rw][col + 1] == '1'){
            dfs(grid, rw , col + 1);
        }
    }
};
