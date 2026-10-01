class Solution {
    static constexpr std::array<pair<int, int>, 4> ARR {{
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    }};
public:
    int orangesRotting(vector<vector<int>>& grid) {
       deque<pair<int,int>> que{};
       for(int i{}; i < grid.size(); ++i){
        for(int j{}; j < grid[0].size(); ++j){
            if(grid[i][j] == 2) que.push_back({i, j}); 
        }
       } 
       return bfs(grid, que);
    }

    int bfs(vector<vector<int>>& grid, deque<pair<int,int>>& que){
        int rw_max = grid.size();
        int cl_max = grid[0].size();
        int max_counter {};
        while(!que.empty()){
            auto[m, n] = que.front();
            que.pop_front();
            int counter = grid[m][n]+1;
            for(auto& arr: ARR){
                auto[i, j] = arr;
                i+=m;
                j+=n;
                if(i >= 0 && i < rw_max && j >= 0 && j < cl_max){
                    if(grid[i][j] == 1){
                        grid[i][j] = counter;
                        max_counter = max(max_counter, counter - 2);
                        que.push_back({i, j});
                    }
                }
            }
        }

       for(int i{}; i < grid.size(); ++i){
        for(int j{}; j < grid[0].size(); ++j){
            if(grid[i][j] == 1) return -1; 
        }
       } 
        return max_counter;
    }
};
