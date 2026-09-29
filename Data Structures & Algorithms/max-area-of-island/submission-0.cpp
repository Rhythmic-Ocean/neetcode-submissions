class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int max_area {};
       int cur_area {};
       for(int i {}; i < grid.size(); ++i){
        for(int j {}; j < grid[0].size(); ++j){
            cur_area = 0;
            if(grid[i][j] == 1){
                cur_area++;
                dfs(grid, i, j, max_area, cur_area);
            }
        }
       } 
       return max_area;
    }
    void dfs(vector<vector<int>>& grid, int rw, int cl, int& max_area, int& cur_area){
        int max_rw = grid.size() - 1;
        int max_cl = grid[0].size() - 1;
        grid[rw][cl] = 0;
        if(rw != 0 && grid[rw - 1][cl] == 1){
            cur_area++;
            dfs(grid, rw -1, cl, max_area, cur_area);
        }
        if(cl != 0 && grid[rw][cl - 1] == 1){
            cur_area++;
            dfs(grid, rw, cl - 1, max_area, cur_area);
        }
        if(rw != max_rw && grid[rw + 1][cl] == 1){
            cur_area++;
            dfs(grid, rw +1, cl, max_area, cur_area);
        }
        if(cl != max_cl && grid[rw][cl + 1] == 1){
            cur_area++;
            dfs(grid, rw, cl + 1, max_area, cur_area);
        }
        if(cur_area > max_area) max_area = cur_area;
    }
};
