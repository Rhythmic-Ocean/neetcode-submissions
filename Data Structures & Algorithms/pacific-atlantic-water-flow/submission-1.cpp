class Solution {
    static constexpr std::array<pair<int, int>, 4> ARR{{
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    }};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int mx_rw = heights.size();
        int mx_col = heights[0].size();
        int total = mx_rw*mx_col;
        vector<vector<int>> finalAns {};
       vector<vector<int>> pac {}; 
       vector<vector<int>> atl{}; 
       vector<bool> s_pac(total, false);
       vector<bool> s_atl(total, false);
       for(int i {}; i < heights.size(); ++i){
        for(int j {}; j < heights[0].size(); ++j){
            if(i == 0 || j == 0){
                pac.push_back({i, j});
            }
            if(i == heights.size() - 1 || j == heights[0].size() - 1){
                atl.push_back({i, j});
            }
        }
        }   
        for(auto& p: pac){
           dfs(heights, p, s_pac); 
        }
        for(auto& a: atl){
           dfs(heights, a, s_atl); 
        }
        for(int i {}; i < total; ++i){
            if(s_pac[i] && s_atl[i]){
               int row = i/mx_col; 
               int col = i % mx_col;
               finalAns.push_back({row, col});
            }
        }
        return finalAns;
    }

    void dfs(vector<vector<int>> & heights, const vector<int>& grid, vector<bool>& s_ocean){
        int p = grid[0]*heights[0].size() + grid[1];
        s_ocean[p] = true;
        for(auto& arr: ARR){
            auto[i, j] = arr;
            i+=grid[0];
            j+=grid[1];
            if(i < 0 || j < 0 || i > heights.size() - 1 || j > heights[0].size() - 1) continue;
            if(heights[i][j] < heights[grid[0]][grid[1]]) continue;
            int p1 = i*heights[0].size() + j;
            if(!s_ocean[p1])
                dfs(heights, {i, j}, s_ocean);
        }
    }
};
